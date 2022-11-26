#include <iostream>
#include "../structures/min_int_heap.cpp"
using namespace std;

void merge(int* array, int low, int middle, int high) {
    IntHeap* lowQueue = new IntHeap(middle - low + 1);
    for (int i = low; i <= middle; i++) { heapInsert(lowQueue, array[i]); }

    IntHeap* highQueue = new IntHeap(high - middle);
    for (int i = middle+1; i <= high; i++) { heapInsert(highQueue, array[i]); }

    int i = low;
    while (lowQueue->n > 0 && highQueue->n > 0) {
        if (heapHead(lowQueue) < heapHead(highQueue)) {
            array[i++] = heapExtractMinimum(lowQueue);
        } else {
            array[i++] = heapExtractMinimum(highQueue);
        }
    }

    while (lowQueue->n > 0) {array[i++] = heapExtractMinimum(lowQueue);}
    while (highQueue->n > 0) {array[i++] = heapExtractMinimum(highQueue);}
}

void mergeSortInplace(int* array, int low, int high) {
    if (low < high) {
        int middle = (low+high)/2;
        mergeSortInplace(array,low,middle);
        mergeSortInplace(array,middle+1,high);
        merge(array,low,middle,high);
    }
}

int* mergeSort(int* array, int n) {
    mergeSortInplace(array,0,n);
    return array;
}