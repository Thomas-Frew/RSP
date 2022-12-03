#include <iostream>
using namespace std;

long int fib(int n) {
    int MAX = 100;
    
    int i;
    long int values[100];

    values[0] = 1;
    values[1] = 1;

    for (int i = 2; i <= n; i++) { values[i] = values[i-1] + values[i-2]; }

    return values[n];
}

int main() {
    cout << fib(50) << endl;

    return 0;
}