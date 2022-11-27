#include <iostream>
using namespace std;

template <typename T>
int partition(T* array, int low, int high) {

    int pivot = high;
    int firsthigh = low;

    for (int i = low; i < high; i++) {
        if (array[i] < array[pivot]) {
            swap(array[i], array[firsthigh]);
            firsthigh++;
        }
    }
    swap(array[pivot], array[firsthigh]);

    return firsthigh;
}


template <typename T>
void quickSortInplace(T* array, int low, int high) {
    if (low < high) {
        int p = partition(array,low,high);
        quickSortInplace(array,low,p-1);
        quickSortInplace(array,p+1,high);
    }
}

template <typename T>
T* quickSort(T* array, int n) {
    quickSortInplace(array, 0, n-1);
    return array;
}
