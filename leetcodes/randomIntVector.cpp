#include <vector>
#include <random>
#include <time.h>
using namespace std;

/// @brief Creates a vector of random integers between -100 and 100
/// @param size Size of the vector
/// @return Random vector
vector<int> randomIntVector(int size, int min = -100, int max = 100) {
    srand(time(NULL));

    vector<int> v;
    for (int i = 0; i < size; i++) {
        v.push_back(random() % (max+min+1) + min);
    }

    return v;
}