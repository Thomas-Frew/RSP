// Leetcode 2087: Greatest Sum Divisible by Three
// Original time: 32:33:00
// O(n) time, O(1) space

// This problem requires breaking down into subproblems, or subroutines.
// From here, the path is obvious. We know how each new number will affect our current sum, and can build our solution incrementally.

#include "../randomIntVector.cpp"
#include "../vectorPrint.cpp"
#include "../startTiming.cpp"
#include "../stopTiming.cpp"

#include <math.h>
using namespace std;

int maxDivisibleSum(vector<int>& nums) {
    vector<vector<int>> dp(nums.size() + 1, vector<int>(3));

    dp[0][0] = 0;
    dp[0][1] = INT32_MIN;
    dp[0][2] = INT32_MIN;

    for (int i = 1; i < nums.size(); i++) {
        int val = nums[i-1];

        dp[i][0] = max(dp[i-1][0], dp[i-1][val%3] + val);
        dp[i][1] = max(dp[i-1][1], dp[i-1][(val+1)%3] + val);
        dp[i][2] = max(dp[i-1][2], dp[i-1][(val+2)%3] + val);
    }

    return dp[nums.size()][0];
}

int main() {
    vector<int> nums = randomIntVector(100,0,100);

    cout << "Input: ";
    vectorPrint(nums);
    cout << endl;

    // Time tracker
    auto start = startTiming();

    int max = maxDivisibleSum(nums);
    cout << "Output: " << max << endl;

    // Time tracker
    stopTiming(start);
}