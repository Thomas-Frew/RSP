#include <random>
#include <time.h>
using namespace std;

/// @brief Creates random integers between min and max
/// @param min Minimum value (inclusive)
/// @param max Maximum value (inclusive, positive)
/// @return Random integer
int randomInt(int min, int max) {
    srand(time(NULL));

    return min + random() % max;

}