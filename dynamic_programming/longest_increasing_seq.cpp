#include "../sorting/array_print.cpp"

const int MAXLEN = 10;

void sequencePrint(int* input, int* p, int x) {
    if (x != -1) {
        sequencePrint(input,p,p[x]);
        cout << input[x] << " ";
    }
}

void longestIncreasingSequence(int* input, int* l, int* p) {
    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < i; j++) {
            if (input[j] < input[i] && l[j] >= l[i]) {
                l[i] = l[j] + 1;
                p[i] = j;
            }
        }
    }

    int MSF = l[0];
    int maxIndex = 0;

    for (int k = 1; k < MAXLEN; k++) {
        if (l[k] > MSF) { 
            MSF = l[k]; 
            maxIndex = k;
        }
    }

    cout << "The longest increasing sequence is: ";
    sequencePrint(input, p, maxIndex);
}

int main() {
    int* input = new int[MAXLEN];

    input[0] = 2;
    input[1] = 9;
    input[2] = 3;
    input[3] = 1;
    input[4] = 5;
    input[5] = 4;
    input[6] = 8;
    input[7] = 6;
    input[8] = 7;

    int* list = new int[MAXLEN];
    int* pred = new int[MAXLEN];

    for (int i = 0; i < MAXLEN; i++) {
        list[i] = 1;
        pred[i] = -1;
    }

    longestIncreasingSequence(input,list,pred);

    return 0;
}