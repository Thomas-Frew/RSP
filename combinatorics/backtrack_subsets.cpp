#include <iostream>
using namespace std;

bool isSolution(int k, int n) { 
    return k == n; 
}

void solutionPrint(int* state, int n) {
    cout << "{";

    for (int i = 0; i < n; i++) {
        if (state[i]) {
            cout << " " << i;
        }
    }

    cout << " }" << endl;
}

void backtrack(int* state, int k, int n) {
    if (isSolution(k,n)) {
        solutionPrint(state,n);
    } else {
        k = k + 1;

        // Create the candidate space manually
        int cSize = 2;

        int* candidates = new int[cSize];
        candidates[0] = true;
        candidates[1] = false;

        for (int i = 0; i < cSize; i++) {
            state[k-1] = candidates[i];
            backtrack(state,k,n);
        }
    }
}

int main() {
    int n = 4;
    int* state = new int[n];

    for (int i = 0; i < n; i++) {
        state[i] = false;
    }

    backtrack(state,0,n);

    return 0;
}