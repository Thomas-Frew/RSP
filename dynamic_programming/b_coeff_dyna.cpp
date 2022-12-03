#include <iostream>
using namespace std;

long int binomialCoeff(int n, int m) {
    const int MAX = 100;
    
    int i;
    long int values[MAX][MAX];

    for (int j = 0; j <= n; j++) {
        values[j][0] = 1;
        values[j][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            values[i][j] = values[i-1][j] + values[i-1][j-1];
        }
    }

    return values[n][m];
}

int main() {
    cout << binomialCoeff(6,4) << endl;

    return 0;
}