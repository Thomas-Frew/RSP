#include <chrono>
using namespace std;
using namespace std::chrono;
 
/// @brief Starts tracking a function's execution time
/// @return Starting point
auto startTiming() {
    auto start = high_resolution_clock::now();
    return start;
}