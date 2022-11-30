#include <string>
#include <iostream>
#include "adjacency_list.cpp"
using namespace std;

class DFS {
    public:
        int nVertices;
        bool* discovered;
        bool* processed;
        int* parentTree;

        int* reachableAncestor;
        char* articulationStates;
        int* treeOutDegree;

        int time;
        int* entry;
        int* exit;

        int* topSort;
        int nUnsorted;

        DFS(int n): nVertices(n) {
            discovered = new bool[nVertices];
            processed = new bool[nVertices];
            parentTree = new int[nVertices];
            
            reachableAncestor = new int[nVertices];
            articulationStates = new char[nVertices];
            treeOutDegree = new int[nVertices];

            time = 0;
            entry = new int[nVertices];
            exit = new int[nVertices];

            topSort = new int[nVertices];
            nUnsorted = nVertices - 1;

            for (int i = 0; i < nVertices; i++) {
                discovered[i] = processed[i] = false;
                parentTree[i] = -1;

                reachableAncestor[i] = -1; 
                articulationStates[i] = 'U';
                treeOutDegree[i] = 0;

                entry[i] = -1;
                exit[i] = -1;

                topSort[i] = -1;
            }
        }
};


// Print commands
void printEntryTimes(DFS* dfs) {
    for (int i = 0; i < dfs->nVertices; i++) {
        cout << dfs->entry[i] << " ";
    }
}

void printExitTimes(DFS* dfs) {
    for (int i = 0; i < dfs->nVertices; i++) {
        cout << dfs->exit[i] << " ";
    }
}

void printReachableAncestors(DFS* dfs) {
    for (int i = 0; i < dfs->nVertices; i++) {
        cout << dfs->reachableAncestor[i] << " ";
    }
}

void printArticulationStates(DFS* dfs) {
    for (int i = 0; i < dfs->nVertices; i++) {
        cout << dfs->articulationStates[i] << " ";
    }
}

void printTopSort(DFS* dfs) {
    for (int i = 0; i < dfs->nVertices; i++) {
        cout << dfs->topSort[i] << " ";
    }
}


// Vertex preprocessing commands
void preprocessVertex(DFS* dfs, int x) {
    cout << "Processed vertex: " << x << endl;
    dfs->reachableAncestor[x] = x;
}


// Vertex postprocessing commands
bool isTreeEdge(DFS* dfs, int x, int y) {
    return (dfs->parentTree[y] == x);
}

void findArticulationState(DFS* dfs, int x) {
    if (dfs->parentTree[x] == -1 && dfs->treeOutDegree[x] > 1) {

        dfs->articulationStates[x] = 'R'; // Root articulation vertex

    } else if (dfs->reachableAncestor[x] == dfs->parentTree[x] && !(dfs->parentTree[dfs->parentTree[x]] == -1)) {

        dfs->articulationStates[x] = 'P'; // Parent articulation vertex

    } else if (dfs->reachableAncestor[x] == x && !(dfs->parentTree[x] == -1)) {

        dfs->articulationStates[dfs->parentTree[x]] = 'B'; // Bridge articulation vertex

        if (dfs->treeOutDegree[x] > 0) {
            dfs->articulationStates[x] = 'B'; // Bridge articulation vertex

            cout << dfs->parentTree[x] << " as bridge ";
        }

    } else {
        dfs->articulationStates[x] = 'S'; // Safe node
    }
}

void postprocessVertex(DFS* dfs, int x) {
    dfs->topSort[dfs->nUnsorted] = x;
    dfs->nUnsorted--;
}


// Edge processing commands
char classifyEdge(DFS* dfs, int x, int y) {
    if (isTreeEdge(dfs,x,y)) { return 'T'; }
    else if (dfs->discovered[y] && !dfs->processed[y]) { return 'B'; }
    else if (dfs->entry[x] < dfs->entry[y] && dfs->processed[y]) { return 'F'; }
    else if (dfs->entry[x] < dfs->entry[y] && dfs->processed[y]) { return 'C'; }
    else { return 'U'; }
}

void updateReachableAncestor(DFS* dfs, int x, int y) {
    if (isTreeEdge(dfs,x,y)) {
        dfs->treeOutDegree[x]++;
    }
    if (dfs->entry[y] < dfs->entry[dfs->reachableAncestor[x]] && dfs->entry[y] > -1) {
        dfs->reachableAncestor[x] = y;
    }
}

void processEdge(DFS* dfs, int x, int y) {
    cout << "Processed edge: " << x << " to " << y << endl;


    cout << "Edge type: " << classifyEdge(dfs,x,y) << endl;
}


// Depth first search
void search(DFS* dfs, Graph* graph, int v = 0) {
    int y;
    EdgeNode* e;

    dfs->discovered[v] = true;
    
    dfs->entry[v] = dfs->time++;
    preprocessVertex(dfs, v);

    e = graph->edges[v];

    while (e != nullptr) {
        y = e->y;

        if (dfs->discovered[y] == false) {
            dfs->parentTree[y] = v;
            processEdge(dfs, v,y);
            search(dfs, graph, y);
        } else {
            processEdge(dfs,v,y);
        }
        
        e = e->next;       
    }

    postprocessVertex(dfs, v);
    dfs->exit[v] = dfs->time++;
    dfs->processed[v] = true;
}


// Sorting systems
void topSort(DFS* dfs, Graph* graph, int start = 0) {
    for (int i = 0; i < graph->nVertices; i++) {
        if (!(dfs->discovered[i])) {
            search(dfs,graph,i);
        }
    }

    printTopSort(dfs);
}


/* Structure Driver (Main)
int main() {
    // Create fixed-size graph
    Graph* graph = new Graph(6);

    // Insert test
    insertEdge(graph,0,1);
    insertEdge(graph,0,2);
    insertEdge(graph,0,4);

    insertEdge(graph,1,2);

    insertEdge(graph,4,3);
    insertEdge(graph,5,3);

    // Print test
    printGraph(graph);

    // Create BFS and assocated parent tree
    DFS* dfs = new DFS(graph->nVertices);

    // BFS test
    cout << endl;
    search(dfs, graph);

    // Time test
    cout << endl << "Entry times: ";
    printEntryTimes(dfs);

    cout << endl << "Exit times: ";
    printExitTimes(dfs);
    cout << endl;

    // Reachable ancestors test
    cout << endl << "Earliest reachable ancestors: ";
    printReachableAncestors(dfs);

    // Articulation states test
    cout << endl << "Articulation states: ";;
    printArticulationStates(dfs);
} */


// Structure driver (top sort)
int main() {
    // Create fixed-size graph
    Graph* graph = new Graph(7,true);

    // Insert test
    insertEdge(graph,0,5,true);
    insertEdge(graph,5,6,true);

    insertEdge(graph,0,1,true);
    insertEdge(graph,1,2,true);
    insertEdge(graph,1,3,true);
    insertEdge(graph,3,4,true);
    
    insertEdge(graph,4,5,true);


    // Print test
    printGraph(graph);


    // Create DFS and perform the search
    DFS* dfs = new DFS(graph->nVertices);

    // Topsort
    cout << endl;
    topSort(dfs, graph);
}

