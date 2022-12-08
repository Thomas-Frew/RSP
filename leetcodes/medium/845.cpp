// Leetcode 845: Longest mountain
// Original time: 1:03:15
// O(n) time, O(1) space

#include "../vectorPrint.cpp"
#include "../randomIntVector.cpp"
#include "../startTiming.cpp"
#include "../stopTiming.cpp"

#include <vector>
using namespace std;


int longestMountainLength(vector<int> nums) {
    int start = 0;
    int end = 0;
    int max = 0;

    int length = nums.size();

    while (end < length) {
        start = end;
        
        if (end+1 < length && nums[end+1] > nums[end]) {    /// If we really are headed for an increase...
            while (nums[end+1] > nums[end]) { end++; }

            if (end+1 < length && nums[end+1] < nums[end]) {    /// If we really are headed for a decline...
                while (nums[end+1] < nums[end]) { end++; }

                max = max > end-start+1 ? max : end-start+1;
            }
        }

        end = start+1 > end ? start+1 : end;
    }

    return max;
}

int main() {
    vector<int> nums = randomIntVector(100);

    cout << "Input: ";
    vectorPrint(nums);
    cout << endl;

    // Time tracker
    auto start = startTiming();

    int max = longestMountainLength(nums);
    cout << "Output: " << max << endl;

    // Time tracker
    stopTiming(start);
}