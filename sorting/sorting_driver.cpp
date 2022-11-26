#include "array_print.cpp"
#include "merge_sort.cpp"
#include "insertion_sort.cpp"

// Sorting test
int main() {
    int array[10] = {9,0,-4,2,2,-2,1,5,-3,-1};

    int* sorted = new int[10];
    sorted = mergeSort(array,10);

    arrayPrint(sorted, 10);
}