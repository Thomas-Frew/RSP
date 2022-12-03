#include <iostream>
using namespace std;

long int fib(long int* cache, int n) {
    if (cache[n] == -1) {
        cache[n] = fib(cache, n-1) + fib(cache, n-2);
    }

    return cache[n];
}


int main() {
    int MAX = 100;
    long int* cache = new long int[MAX];

    for (int i = 0; i < MAX; i++) { cache[i] = -1; }

    cache[0] = 1;
    cache[1] = 1;

    cout << fib(cache, 50) << endl;

    return 0;
}