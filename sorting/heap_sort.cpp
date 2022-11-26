#include <string>
#include <iostream>
#include <math.h>
#include "../structures/min_int_heap.cpp"
#include "array_print.cpp"
using namespace std;

int* heapSort(int* data, int n) {
    int* sorted = new int[n];
    
    IntHeap* heap = new IntHeap(n);
    heap = heapCreate(heap, data, n);

    for (int i = 0; i < n; i++) {
        sorted[i] = heapExtractMinimum(heap);
    }

    return sorted;
}

// Sorting test
int main() {
    int array[10] = {9,0,-1,8,2,2,-3,7,8,1};

    int* sorted = new int[10];
    sorted = heapSort(array,10);

    arrayPrint(sorted, 10);
}