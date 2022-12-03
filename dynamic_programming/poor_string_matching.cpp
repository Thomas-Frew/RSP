#include <iostream>
using namespace std;

int MATCH = 0;
int INSERT = 1;
int DELETE = 2;

int indel() { return 1; }

int match(char s, char t) { 
    if (s == t) { return 0; }
    else { return 1; }
}

int stringCompare(char* s, char* t, int i, int j) {
    int k;
    int opt[3];
    int minCost;

    if (i == 0) { return i * indel(); }
    if (j == 0) { return j * indel(); }

    opt[MATCH] = stringCompare(s,t,i-1,j-1) + match(s[i],t[j]);
    opt[INSERT] = stringCompare(s,t,i,j-1) + indel();
    opt[DELETE] = stringCompare(s,t,i-1,j) + indel();

    minCost = opt[MATCH];
    for (int k = INSERT; k <= DELETE; k++) {
        if (opt[k] < minCost) {
            minCost = opt[k];
        }
    }

    return minCost;
}

int main() {
    char text[9] = "minimums";
    char search[4] = "nam";

    cout << stringCompare(search, text, 4, 8) << endl;

    return 0;
}