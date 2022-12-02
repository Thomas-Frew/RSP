#include "../graphs/adjacency_matrix.cpp"
#include <random>
#include <time.h>
using namespace std;

int* randomSolution(Graph* g, int* path, int seed, int start = 0) {
    srand(seed);

    bool* isUnused = new bool[g->nVertices];

    for (int i = 0; i < g->nVertices; i++) { isUnused[i] = true; }
    for (int i = 0; i < g->nVertices+1; i++) { path[i] = -1; }

    int v = start;
    path[0] = v;
    isUnused[0] = false;

    int i = 1;
    int clock = 0;

    while (i < g->nVertices && clock < 1000) {
        int next = random() % 6;
        int weight = g->weights[v][next];

        if (isUnused[next] && weight < 10000000) {

            isUnused[next] = false;

            path[i] = next;
            v = next;

            i++;
        }
        clock++;
    }

    path[i] = start;
    return path;
}

int solutionCost(Graph* g, int* solution) {
    int cost = 0;

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

void randomSampling(Graph* g, int* sol, int iterations) {

    int* rSol = new int[g->nVertices+1];
    int bestCost = numeric_limits<int>::max();

    for (int i = 0; i < iterations; i++) {
        rSol = randomSolution(g, rSol, i);
        int cost = solutionCost(g,rSol);

        if (cost < bestCost) {
            bestCost = cost;

            for (int i = 0; i < g->nVertices+1; i++) {
                sol[i] = rSol[i];
            }
        }
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
    randomSampling(g, solution, 10000);

    cout << "The best solution is: ";
    printSolution(solution, g->nVertices + 1);

    int cost = solutionCost(g, solution);
    cout << "Costing: " << cost << endl;

    return 0;
}