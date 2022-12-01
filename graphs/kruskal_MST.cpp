#include "adjacency_list.cpp"
#include "../structures/set_union.cpp"
#include <iostream>


EdgeNode** graph2edgeArray(Graph* g) {
    EdgeNode** edgeArray = new EdgeNode*[g->nEdges];

    int c = 0; // Counter
    for (int i = 0; i < g->nVertices; i++) {
        EdgeNode* e = g->edges[i];

        while (e != nullptr) {
            edgeArray[c++] = e;
            e = e->next;
        }
    }

    return edgeArray;
}

int partition(EdgeNode** array, int low, int high) {

    int pivot = high;
    int firsthigh = low;

    for (int i = low; i < high; i++) {
        if (array[i]->weight < array[pivot]->weight) {
            swap(array[i], array[firsthigh]);
            firsthigh++;
        }
    }
    swap(array[pivot], array[firsthigh]);

    return firsthigh;
}

void quickSortInplace(EdgeNode** array, int low, int high) {
    if (low < high) {
        int p = partition(array,low,high);
        quickSortInplace(array,low,p-1);
        quickSortInplace(array,p+1,high);
    }
}

void kruskalsAlgorithm(Graph* g, int start = 0) {
    SetUnion* s = new SetUnion(g->nEdges);
    EdgeNode** edgeArray = graph2edgeArray(g);

    quickSortInplace(edgeArray,0,g->nEdges - 1);

    for (int i = 0; i < g->nEdges; i++) {
        if(!isSameComponent(s, edgeArray[i]->x, edgeArray[i]->y)) {
            cout << "Union of " << edgeArray[i]->x << " and " << edgeArray[i]->y << endl;
            unionSets(s, edgeArray[i]->x, edgeArray[i]->y);
        }
    }
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

    // Kruskal test
    cout << endl;
    kruskalsAlgorithm(graph);

    return 0;
}