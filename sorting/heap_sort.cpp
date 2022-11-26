#include <string>
#include <iostream>
#include <math.h>
#include "../structures/min_int_heap.cpp"
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