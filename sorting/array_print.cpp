#include <iostream>
using namespace std;

template <typename T>
void arrayPrint(T* array, int n) {
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}