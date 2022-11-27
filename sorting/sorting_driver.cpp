
#include "merge_sort.cpp"
#include "insertion_sort.cpp"
#include "quick_sort.cpp"
#include "shell_sort.cpp"
#include "triple_sort.cpp"
#include "array_print.cpp"

// Sorting test
int main() {
    int n = 10;
    int array[10] = {9,0,-4,2,2,-2,1,5,-3,-1};

    // int array[16] = {0,-1,1,1,-1,0,0,1,-1,1,0,1,-1,0,1,-1}; (For testing tripleSort)

    int* sorted = new int[n];
    sorted = quickSort(array,n);

    arrayPrint(array, n);
}