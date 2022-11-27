#include <iostream>
using namespace std;

template <typename T>
void subInsertionSort(T* array, int n, int shell, int offset) {
    for (int i = shell + offset; i < n; i += shell) {
        int j = i;
        while (array[j] < array[j-shell] && j >= shell) {
            swap(array[j], array[j-shell]);
            j -= shell;
        }
    }
}

template <typename T>
void shellSort(T* array, int n, int shell) {
    shell /= 2;

    if (shell > 0) {
        for (int i = 0; i < shell; i++) {
            subInsertionSort(array,n,shell,i);
        }
        shellSort(array,n,shell);
    }
}

template <typename T>
T* shellSort(T* array, int n) {
    shellSort(array,n,n);
    return array;
}