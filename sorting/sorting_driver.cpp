#include "array_print.cpp"
#include "merge_sort.cpp"

// Sorting test
int main() {
    int array[10] = {9,0,-1,8,2,2,-3,7,8,1};

    int* sorted = new int[10];
    sorted = mergeSort(array,10);

    arrayPrint(sorted, 10);
}