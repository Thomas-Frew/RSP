#include "../graphs/adjacency_list.cpp"
#include <iostream>
using namespace std;

bool isSolution(int* state, int k, int d) { 
    return state[k] == d; 
}

void solutionPrint(int* state, int k) {
    for (int i = 0; i < k+1; i++) {
        cout << state[i] << " ";
    }
    cout << endl;
}

void generateCandidates(int* state, int k, int n, int* candidates, int* nCandidates, Graph* g) {
    bool* isUsed = new bool[n];

    for (int i = 0; i < n; i++) {isUsed[i] = false; }
    for (int i = 0; i < k; i++) {isUsed[state[i]] = true; }

    if (k == 0) {
        candidates[0] = 0;
        *nCandidates = 1;
    } else {
        int last = state[k-1];
        EdgeNode* p = g->edges[last];

        while (p != nullptr) {
            int w = p->y;
            
            if (!isUsed[w]) {
                candidates[*nCandidates] = w;
                *nCandidates = *nCandidates + 1;
            }

            p = p->next;
        }
    }
}

void backtrack(int* state, int k, int n, Graph* g, int d) {
    if (isSolution(state,k,d)) {
        solutionPrint(state,k);
    } else {
        k = k + 1;

        int* nCandidates = new int;
        int* candidates = new int[n-k];

        generateCandidates(state,k,n,candidates,nCandidates,g);

        for (int i = 0; i < *nCandidates; i++) {
            state[k] = candidates[i];
            backtrack(state,k,n,g,d);
        }
    }
}

int main() {
    int n = 8;
    Graph* g = new Graph(8,true);

    insertEdge(g,0,1,true);
    insertEdge(g,0,3,true);
    insertEdge(g,0,5,true);

    insertEdge(g,1,2,true);

    insertEdge(g,2,3,true);
    
    insertEdge(g,3,4,true);
    
    insertEdge(g,4,6,true);
    insertEdge(g,4,7,true);

    insertEdge(g,5,6,true);

    insertEdge(g,6,3,true);
    insertEdge(g,6,7,true);

    int* path = new int[n];

    for (int i = 0; i < n; i++) {
        path[i] = -1;
    }

    backtrack(path,-1,n,g,7);
}