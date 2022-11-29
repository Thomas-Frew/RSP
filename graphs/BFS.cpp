#include <string>
#include <iostream>
#include "adjacency_list.cpp"
#include "../structures/linear_queue.cpp"
using namespace std;

class BFS {
    public:
        int nVertices;
        bool* discovered;
        bool* processed;
        int* parentTree;
        Queue<int>* searchQueue;

        BFS(int n): nVertices(n) {
            discovered = new bool[nVertices];
            processed = new bool[nVertices];
            parentTree = new int[nVertices];

            for (int i = 0; i < nVertices; i++) {
                discovered[i] = processed[i] = false;
                parentTree[i] = -1;
            }
        }
};

void processVertex(int x) {
    cout << "Processed vertex: " << x << endl;
}

void processEdge(int x, int y) {
    cout << "Processed edge: " << x << " to " << y << endl;
}

void search(BFS* bfs, Graph* g, int start = 0) {
    Queue<int>** q = &(bfs->searchQueue);
    EdgeNode* edge;
    int v;
    int e;

    enqueue(q, start);
    bfs->discovered[start] = true;

    while(!(isEmpty(*q))) {
        v = dequeue(q); 

        // processVertex(v);
        bfs->processed[v] = true;

        edge = g->edges[v];
        while (edge != nullptr) {
            e = edge->y;
            
            if (bfs->processed[e] == false || g->directed) {
                // processEdge(v,e);
            }

            if (bfs->discovered[e] == false) {
                enqueue(q,e);
                bfs->discovered[e] = true;
                bfs->parentTree[e] = v;
            }
            
            edge = edge->next;
        }

        // Post-process vertex
    }
}

void findPath(int* parentTree, int start, int end) {
    if (start == end || end == -1) {
        cout << end << " ";
    } else {
        findPath(parentTree, start, parentTree[end]);
        cout << end << " ";
    }
}

int countConnectedComponents(Graph* graph) {
    int connectedComponents = 0;
    BFS* bfs = new BFS(graph->nVertices);

    for (int i = 0; i < graph->nVertices; i++) {
        if (bfs->discovered[i] == false) {
            connectedComponents++;
            search(bfs, graph, i);
        }
    }

    return connectedComponents;
}

int main() {
    // Create fixed-size graph
    Graph* graph = new Graph(8);

    // Insert test
    insertEdge(graph,0,1);
    insertEdge(graph,0,2);
    insertEdge(graph,0,4);

    insertEdge(graph,1,2);
    insertEdge(graph,1,3);

    insertEdge(graph,4,3);
    insertEdge(graph,5,3);

    insertEdge(graph,6,7);

    // Print test
    printGraph(graph);

    // Create BFS and assocated parent tree
    BFS* bfs = new BFS(graph->nVertices);

    // BFS test
    cout << endl;
    search(bfs, graph);

    // Pathfinding test
    cout << endl;
    findPath(bfs->parentTree, 0,3);

    // Connected components test
    cout << endl;
    cout << "Connected components: " << countConnectedComponents(graph) << endl;

    return 0;
}
