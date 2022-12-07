#include "../graphs/adjacency_matrix.cpp"
#include <iostream>
#include <random>
#include <time.h>
using namespace std;

const double COOLING_STEPS = 100;
const double STEPS_PER_COOL = 500;
const double COOLING_FRACTION = 0.8;

int* randomSolution(Graph* g, int* path, int start = 0) {
    srand(time(NULL));

    bool* isUnused = new bool[g->nVertices];

    for (int i = 0; i < g->nVertices; i++) { isUnused[i] = true; }
    for (int i = 0; i < g->nVertices+1; i++) { path[i] = -1; }

    // Setup path
    int v = start;
    path[0] = v;
    isUnused[0] = false;

    // Iterators
    int i = 1;
    int clock = 0;

    while (i < g->nVertices && clock < 1000) {
        int next = random() % g->nVertices;
        int weight = g->weights[v][next];

        if (isUnused[next] && weight < WEIGHTMAX) {

            isUnused[next] = false;

            path[i] = next;
            v = next;

            i++;
        }
        clock++;
    }

    // Close off the path and return it
    path[i] = start;
    return path;
}

int findIndex(Graph* g, int* path, int n) {
    for (int i = 0; i < g->nVertices; i++) {
        if (path[i] == n) return i;
    }
}

void transition(Graph* g, int* path, int n1, int n2) {
    int i1 = findIndex(g,path,n1);
    int i2 = findIndex(g,path,n2);

    path[i1] = n2;
    path[i2] = n1;
}

double solutionCost(Graph* g, int* solution) {
    double cost = 0;

    for (int i = 0; i < g->nVertices; i++) {
        cost += g->weights[solution[i]][solution[i+1]];
    }

    return cost;
}

void printSolution(int* sol, int n) {
    for (int i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }
    cout << endl;
}

void anneal(Graph* g, int* sol) {
    int n1, n2;                                     // Swappers
    int i, j;                                       // Counters
    double temperature = 1.00;                         // Temperature
    double currentCost = numeric_limits<int>::max();   // Current cost of the TSP path
    double startCost;                                  // Current cost of the TSP path
    double delta = 0;                               // Cost difference between current and new path
    double flip;                                    // Random transition-making threshold
    double merit;                                   // Random transition-making attempt
    double exponent;                                // Math storage

    randomSolution(g,sol);
    currentCost = solutionCost(g,sol);

    for (i = 0; i < COOLING_STEPS; i++) {
        temperature *= COOLING_FRACTION;
        startCost = currentCost;

        for (j = 0; j < STEPS_PER_COOL; j++) {
            n1 = random() % (g->nVertices-1) + 1;
            n2 = random() % (g->nVertices-1) + 1;

            flip = random();
            transition(g,sol,n1,n2);
            delta = solutionCost(g,sol);
            exponent = (-delta/currentCost)/(temperature);
            merit = pow(M_E, exponent);

            if (delta < currentCost || merit > flip) {
                currentCost = delta;

            } else {
                transition(g,sol,n2,n1);
            }
        }

        if ((currentCost-startCost) < 0.0) {
            temperature /= COOLING_FRACTION;
        }

        temperature = temperature/COOLING_FRACTION;
    }
}


int main() {
    Graph* g = new Graph(6);

    insertEdge(g,0,1,false,1);
    insertEdge(g,1,2,false,1);
    insertEdge(g,2,3,false,1);
    insertEdge(g,3,4,false,1);
    insertEdge(g,4,5,false,1);
    insertEdge(g,5,0,false,1);

    insertEdge(g,0,4,false,2);
    insertEdge(g,1,3,false,2);

    insertEdge(g,0,3,false,3);
    insertEdge(g,1,4,false,3);

    insertEdge(g,2,5,false,4);

    printGraph(g);

    int* solution = new int[g->nVertices+1];
    anneal(g,solution);

    printSolution(solution,g->nVertices+1);


    return 0;
}