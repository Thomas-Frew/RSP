#include <limits>
#include <iostream>
using namespace std;

class Graph {
    public:
        int** weights;
        int nVertices;
        int nEdges;

        Graph(int n) {
            nVertices = n;
            nEdges = 0;

            weights = new int*[n];

            for (int i = 0; i < n; i++) {
                weights[i] = new int[n];

                for (int j = 0; j < n; j++) {
                    weights[i][j] = numeric_limits<int>::max();
                }
            }
        }
};

void insertEdge(Graph* g, int x, int y, bool directed = false, int weight = 1) {
    g->weights[x][y] = weight;

    if (!directed) {
        insertEdge(g,y,x,true,weight);
    } else {
        g->nEdges++;
    }
}

void printGraph(Graph* g) {
    cout << "Number of Vertices: " << g->nVertices << endl;
    cout << "Number of Edges: " << g->nEdges << endl;

    cout << endl;
    int count;

    for (int i = 0; i < g->nVertices; i++) {
        cout << i << " is connected to: ";

        for (int j = 0; j < g->nVertices; j++) {
            if (g->weights[i][j] < numeric_limits<int>::max()) cout << j << " ";
        }

        cout << endl;
    }
}

/* Strcutre driver 
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

    cout << endl;
    for (int i = 0; i < graph->nVertices; i++) {
        for (int j = 0; j < graph->nVertices; j++) {
            cout << graph->weights[i][j] << "\t \t";
        }    
        cout << endl;
    }

    return 0;
}
*/