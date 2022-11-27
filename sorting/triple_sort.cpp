// Only applicable to arrays with three unique elements
template <typename T> 
T findMinimum(T* array, int n) { 
    T min = array[0];
    for (int i = 1; i < n; i++) {
        min = array[i] < min ? array[i] : min;
    }
    return min;
}

template <typename T> 
T findMaximum(T* array, int n) { 
    T max = array[0];
    for (int i = 1; i < n; i++) {
        max = array[i] > max ? array[i] : max;
    }
    return max;
}

template <typename T> 
T* tripleSort(T* array, int n) {
    T min = findMinimum(array, n);
    T max = findMaximum(array, n);

    int minIndex = 0;
    int maxIndex = n-1;

    for (int i = 0; i < n; i++) {
        if (array[i] == min) {
            swap(array[i], array[minIndex]);
            minIndex++;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        if (array[i] == max) {
            swap(array[i], array[maxIndex]);
            maxIndex--;
        }
    }

    return array;
}