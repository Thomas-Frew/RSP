#include <iostream>
using namespace std;

template <typename T>
int partition(T* list, int left, int right) {
    int pivot = right;
    int firstGreater = left;

    for (int i = left; i < right; i++) {
        if (list[i] < list[pivot]) {            // We are essentially pushing elements smaller than out pivot down
            swap(list[i],list[firstGreater]);
            firstGreater++;
        }
    }

    swap(list[pivot], list[firstGreater]);
    return firstGreater;
}

template <typename T>
int quickSelect(T* list, int left, int right, int k) {
    if (left == right) {
        return list[left];
    }

    int pivotIndex = partition(list, left, right);

    if (pivotIndex == k) {
        return list[pivotIndex];
    } else if (pivotIndex > k) {
        return quickSelect(list, left, pivotIndex - 1, k);
    } else {
        return quickSelect(list, pivotIndex + 1, right, k);
    }
}

int main() {
    int testData[9] = {1,4,9,3,6,8,7,2,10};

    cout << quickSelect(testData,0,9,9) << endl;

    return 0;
}