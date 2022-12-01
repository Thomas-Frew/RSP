#include "adjacency_matrix.cpp"
#include <iostream>
using namespace std;

void floydWashallPrint(Graph* g) {
    for (int i = 0; i < g->nVertices; i++) {
        for (int j = 0; j < g->nVertices; j++) {
            cout << "Path " << i << " to " << j << " is " << g->weights[i][j] << " units." << endl; 
        }
    }
}

void floydWashallAlgorithm(Graph* g) {
    for (int k = 0; k < g->nVertices; k++) {
        for (int i = 0; i < g->nVertices; i++) {
            for (int j = 0; j < g->nVertices; j++) {
                int throughK = g->weights[i][k] + g->weights[k][j];
                if (throughK < g->weights[i][j]) {
                    g->weights[i][j] = throughK;
                }
            }
        }
    }

    floydWashallPrint(g);
}

int main() {
    Graph* graph = new Graph(7);

    insertEdge(graph,0,1,false,5);
    insertEdge(graph,0,3,false,15);
    insertEdge(graph,0,6,false,20);

    insertEdge(graph,1,2,false,10);
    insertEdge(graph,1,3,false,5);

    insertEdge(graph,2,4,false,20);

    insertEdge(graph,3,4,false,20);
    insertEdge(graph,3,5,false,5);

    insertEdge(graph,4,5,false,10);

    printGraph(graph);

    floydWashallAlgorithm(graph);

    return 0;
}