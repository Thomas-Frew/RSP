#include <string>
#include <iostream>
#include <math.h>
using namespace std;

class IntHeap {
    public:
        int MAX_SIZE;
        int MAX_LEVEL;
        int n = 0;
        int* items;

        IntHeap(int m): MAX_SIZE(m) { 
            items = new int[MAX_SIZE]; 
            for (int i = 0; i < MAX_SIZE; i++) {
                items[i] = 0;
            }

            MAX_LEVEL = ceil(log2(MAX_SIZE));
        }
};

int heapParent(int i) {
    if (i == 0) return -1;
    return (i-1)/2;
}

int heapYoungChild(int i) {
    return 2*i + 1;
}

void heapBubbleUp(IntHeap* heap, int i) {
    if (heapParent(i) == -1) return; // No parent, root of heap

    if (heap->items[i] < heap->items[heapParent(i)]) {
        swap(heap->items[i], heap->items[heapParent(i)]);
        heapBubbleUp(heap, heapParent(i));
    }
}

void heapInsert(IntHeap* heap, int item) {
    if (heap->n + 1 > heap->MAX_SIZE) {
        cout << "Warning! Maximum heap size exceeded" << endl;
    } else {
        heap->items[heap->n] = item;
        heapBubbleUp(heap, heap->n);
        heap->n++;
    }
}

void heapBubbleDown(IntHeap* heap, int p) {
    int young_child = heapYoungChild(p);
    int lighter_index = p;

    for (int i = 0; i <= 1; i++) {
        if (young_child+i < heap->n) {
            if (heap->items[young_child+i] < heap->items[lighter_index]) { lighter_index = young_child+i; }
        }
    }

    if (lighter_index != p) {
        swap(heap->items[p], heap->items[lighter_index]);
        heapBubbleDown(heap, lighter_index);
    }
}

int heapExtractMinimum(IntHeap* heap) {
    if (heap->n == 0) {
        cout << "Warning! empty heap";
        return -1;
    } else {
        int min = heap->items[0];

        heap->items[0] = heap->items[heap->n-1];
        heap->n = heap->n-1;
        heapBubbleDown(heap, 0);

        return min;
    }
}    

void heapPrint(IntHeap* heap) {
    for (int i = 0; i < heap->n; i++) {
        cout << heap->items[i] << " ";
    }
}

void heapPrintLevels(IntHeap* heap, int l = 1) {
    if (l <= heap->MAX_LEVEL) {
        cout << "Level " << l << ": ";
        for (int i = pow(2,l-1) - 1; i < pow(2,l) - 1; i++) {
            if (i < heap->MAX_SIZE && i < heap->n) cout << heap->items[i] << " ";
        }
        cout << endl;

        l++;
        heapPrintLevels(heap, l);
    }
}

int heapHead(IntHeap* heap) { return heap->items[0]; }

IntHeap* heapCreate(IntHeap* heap, int* data, int n) {
    for (int i = 0; i < n; i++) {
        heapInsert(heap,data[i]);
    }

    return heap;
}

/* Structure driver
int main() {
    // Initialise the heap with 123 spaces
    IntHeap* heap = new IntHeap(123);

    // Insertion test
    heapInsert(heap,10);
    heapInsert(heap,5);
    heapInsert(heap,6);
    heapInsert(heap,15);
    heapInsert(heap,12);
    heapInsert(heap,8);
    heapInsert(heap,2);
    heapInsert(heap,1);
    heapInsert(heap,9);
    heapInsert(heap,7);
    heapInsert(heap,11);
    heapInsert(heap,17);
    heapInsert(heap,19);
    heapInsert(heap,3);
    heapInsert(heap,4);
    heapInsert(heap,13);
    heapInsert(heap,14);
    heapInsert(heap,16);

    // Print test
    heapPrintLevels(heap);

    return 0;
} */