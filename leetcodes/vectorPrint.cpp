#include <iostream>
#include <vector>
using namespace std;

/// @brief Prints out a vector
/// @tparam T Type of vector
/// @param v Vector
template <typename T>
void vectorPrint(vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}