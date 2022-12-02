#include <iostream>
using namespace std;

bool isSolution(int k, int n) { 
    return k == n - 1; 
}

void solutionPrint(int* state, int n) {
    for (int i = 0; i < n; i++) { cout << " " << state[i]; }
}

void generateCandidates(int* state, int k, int n, int* candidates, int* nCandidates) {
    bool* isUsed = new bool[n];

    for (int i = 0; i < n; i++) {isUsed[i] = false; }
    for (int i = 0; i < k; i++) {isUsed[state[i]] = true; }

    *nCandidates = 0;

    for (int i = 0; i < n; i++) {
        if (!isUsed[i]) {
            candidates[*nCandidates] = i;
            *nCandidates = *nCandidates + 1;
        }
    }
}

void backtrack(int* state, int k, int n) {
    if (isSolution(k,n)) {
        solutionPrint(state,n);
    } else {
        k = k + 1;

        int* nCandidates = new int;
        int* candidates = new int[n-k];

        generateCandidates(state,k,n,candidates,nCandidates);

        for (int i = 0; i < *nCandidates; i++) {
            state[k] = candidates[i];
            backtrack(state,k,n);
        }
    }
}

int main() {
    int n = 4;
    int* state = new int[n];

    for (int i = 0; i < n; i++) {
        state[i] = -1;
    }

    backtrack(state,-1,n);

    return 0;
}