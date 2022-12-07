// Leetcode 396: Rotate Function
// Original time: 30:47
// O(n) time, O(1) space

#include "../vectorPrint.cpp"
#include "../randomIntVector.cpp"
#include "../startTiming.cpp"
#include "../stopTiming.cpp"

#include <vector>
using namespace std;

int findMaxRotation(vector<int> array) {
    int count = array.size();
    int sum = 0;
    int rotate = 0;

    for (int i = 0; i < count; i++) {
        sum += array[i];
        rotate += i * array[i];
    }

    int maxSum = rotate;

    // Using the observation that F(n) = F(n-1) + sum - n(array[n])
    for (int i = count - 1; i > -1; i--) {
        rotate = rotate + sum - count*array[i];
        maxSum = max(maxSum, rotate);
    }

    return maxSum;
}


int main() {
    vector<int> nums = randomIntVector(100);

    cout << "Input: ";
    vectorPrint(nums);
    cout << endl;

    // Time tracker
    auto start = startTiming();

    int max = findMaxRotation(nums);
    cout << "Output: " << max << endl;

    // Time tracker
    stopTiming(start);
}