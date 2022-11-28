#include <string>
#include <iostream>
using namespace std;

class EdgeNode {
    public:
        int y;
        int weight;
        EdgeNode* next = nullptr;

        EdgeNode(int _y, int w, EdgeNode* n): y(_y), weight(w), next(n) {}
};

class Graph {
    public:
        EdgeNode** edges;
        int* degrees;

        int nVertices;
        int nEdges;
        bool directed;

        Graph(int v, bool d = false) {
            edges = new EdgeNode*[v];
            degrees = new int[v];

            for (int i = 0; i <= v; i++) degrees[i] = 0;
            for (int i = 0; i <= v; i++) edges[i] = nullptr;

            nVertices = v;
            nEdges = 0;
            directed = d;
        }
};

void insertEdge(Graph* graph, int x, int y, bool directed = false, int weight = 0) {
    EdgeNode* edge = new EdgeNode(y, weight, graph->edges[x]);

    graph->edges[x] = edge;
    graph->degrees[x] = graph->degrees[x] + 1;

    if (directed == false) {
        insertEdge(graph,y,x,true,weight);
    } else {
        graph->nEdges = graph->nEdges+1;
    }
}

bool edgeSearch(EdgeNode* edge, int search) {
    if (edge == nullptr) return false;
    else if (edge->y == search) return true;
    else edgeSearch(edge->next, search);
}

bool hasEdge(Graph* graph, int x, int y) {
    return edgeSearch(graph->edges[x], y);
}

void printGraph(Graph* graph) {
    cout << "Number of Vertices: " << graph->nVertices << endl;
    cout << "Number of Edges: " << graph->nEdges << endl;

    cout << endl;
    int count;

    for (int i = 0; i < graph->nVertices; i++) {
        cout << i << " is connected to: ";

        EdgeNode* vertex = graph->edges[i];

        while (vertex != nullptr) {
            cout << vertex->y << " ";
            vertex = vertex->next;
        }
        cout << endl;
    }
}

// Structure driver
int main() {
    Graph* graph = new Graph(5);

    // Insert test
    insertEdge(graph,0,1);
    insertEdge(graph,0,2);
    insertEdge(graph,0,3);
    insertEdge(graph,0,4);

    insertEdge(graph,1,2);
    insertEdge(graph,1,3);

    insertEdge(graph,4,3);

    // Print test
    printGraph(graph);

    // Search test
    cout << endl;
    cout << hasEdge(graph,0,1) << endl; // True
    cout << hasEdge(graph,4,2) << endl; // False

    return 0;
}