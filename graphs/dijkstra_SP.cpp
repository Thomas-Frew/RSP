#include "adjacency_list.cpp"
#include <iostream>
#include <limits>

using namespace std;

void dijkstraPrint(Graph* g, int* parentTree, int* distance) {
    for (int i = 0; i < g->nVertices; i++) {
        cout << "Shortest path to " << i << " is " << distance[i] << " units long." << endl;

        int p = i;
        cout << "This path is: ";
        while (p != -1) {
            cout << p << " ";
            p = parentTree[p];
        }
        cout << endl;
    }
}

void dijkstrasAlgorithm(Graph* g, int start = 0) {
    int* parentTree = new int[g->nVertices];
    int* distance = new int[g->nVertices];
    bool* inTree = new bool[g->nVertices];

    int v;
    int w;

    EdgeNode* p;
    int weight;

    int dist;

    for (int i = 0; i < g->nVertices; i++) {
        parentTree[i] = -1;
        distance[i] = numeric_limits<int>::max();
        inTree[i] = false;
    }

    v = start;
    distance[start] = 0;

    while (inTree[v] == false) {
        inTree[v] = true;

        p = g->edges[v];

        while (p != nullptr) {
            w = p->y;
            weight = p->weight;

            if (distance[w] > distance[v] + weight) {
                distance[w] =  distance[v] + weight;
                parentTree[w] = v;
            }

            p = p->next;
        }

        v = 0;
        dist = numeric_limits<int>::max();

        for (int i = 0; i < g->nVertices; i++) {
            if (dist > distance[i] && inTree[i] == false) {
                dist = distance[i];
                v = i;
            }
        }
    }

    dijkstraPrint(g,parentTree,distance);
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

    // Dijkstra test
    dijkstrasAlgorithm(graph);

    return 0;
}