#include "adjacency_list.cpp"
#include <iostream>
#include <limits>

using namespace std;

void primPrint(Graph* g, int* parents) {
    for (int i = 0; i < g->nVertices; i++) {
        cout << i << "'s parent is " << parents[i] << endl;
    }
}

void primsAlgorithm(Graph* g, int start = 0) {
    
    bool* inTree = new bool[g->nVertices];
    int* distances = new int[g->nVertices];
    int* parentTree = new int[g->nVertices];
    int v;
    int w;
    int totalCost = 0;
    int weight;
    int dist;
    EdgeNode* p;

    for (int i = 0; i < g->nVertices; i++) {
        inTree[i] = false;
        distances[i] = numeric_limits<int>::max();
        parentTree[i] = -1;
    }

    v = start;

    while (inTree[v] == false) {
        inTree[v] = true;

        p = g->edges[v];

        // Update the minimum lengths to each vertex, and the parent coming from it
        while (p != nullptr) {
            w = p->y;
            weight = p->weight;

            if (weight < distances[w] && inTree[w] == false) {
                distances[w] = weight;
                parentTree[w] = v;
            }
            
            p = p->next;
        }

        v = 0;
        dist =  numeric_limits<int>::max();

        // Select the next vertex to assess
        for (int i = 0; i < g->nVertices; i++) {
            if (distances[i] < dist && inTree[i] == false) {
                dist = distances[i];
                v = i;
            }
        }

        if (v != start) { totalCost += dist; }
    }

    cout << endl;
    cout << "Total cost: " << totalCost;
    cout << endl;
    primPrint(g, parentTree);
}

int main() {
    // Create fixed-size graph
    Graph* graph = new Graph(7);

    // Insert test
    insertEdge(graph,0,1,false,10);
    insertEdge(graph,0,5,false,5);

    insertEdge(graph,1,2,false,15);
    insertEdge(graph,1,6,false,10);

    insertEdge(graph,2,3,false,20);

    insertEdge(graph,3,4,false,5);
    insertEdge(graph,3,6,false,5);

    insertEdge(graph,4,6,false,10);    

    insertEdge(graph,5,6,false,15);

    // Print test
    printGraph(graph);

    // Prim test
    primsAlgorithm(graph);


    return 0;
}