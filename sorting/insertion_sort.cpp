#include <iostream>
using namespace std;
#include "array_print.cpp"

template <typename T>
T* insertionSort(T* array, int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (array[j] < array[j-1] && j > 0) {
            swap(array[j], array[j-1]);
            j--;
        }
    }

    return array;
}

// Sorting test
int main() {
    int array[10] = {9,0,-1,8,2,2,-3,7,8,1};

    int* sorted = new int[10];
    sorted = insertionSort(array,10);

    arrayPrint(sorted, 10);
}