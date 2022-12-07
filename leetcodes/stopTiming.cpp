#include <chrono>
#include <iostream>
using namespace std;
using namespace std::chrono;
 
/// @brief Stop tracking a function's execution time, and report it
void stopTiming(std::chrono::_V2::system_clock::time_point start) {
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
 
    // Get duration and cast it to milliseconds
    auto duration = duration_cast<microseconds>(stop - start);
 
    cout << "Algorithm executed in " << duration.count() << " microseconds." << endl;
}