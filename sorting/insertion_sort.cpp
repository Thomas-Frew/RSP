#include <iostream>
using namespace std;

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