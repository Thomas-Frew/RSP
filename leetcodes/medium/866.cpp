// Leetcode 866: Prime Palindrome
// Original time: 54:20
// O(n) time, O(1) space

#include <string>
#include <algorithm>

#include "../randomInt.cpp"
#include "../startTiming.cpp"
#include "../stopTiming.cpp"

using namespace std;

long int isPrime(int n) {
    if (n == 1) { return false; }

    for (int j = 2; j*j <= n; j++) {
        if (n % j == 0) { return false; }
    }

    return true;
}

int primePalindrome(int n) {

    for (int i = 1; i <= 9; i++) {
        if (i >= n && isPrime(i)) { return i; }
    }

    if (11 >= n && isPrime(11)) { return 11; }

    for (int i = 10; i <= 20000; i++) {
        string prefix = to_string(i);

        string reversed = prefix;
        reversed.pop_back();
        reverse(reversed.begin(), reversed.end());
        
        string full = prefix + reversed;
        int number = stoi(full);

        if (number >= n && isPrime(number)) { return number; }
    }

    return -1;
}

int main() {
    // Time tracker
    auto start = startTiming();

    int n = randomInt(2,2*pow(10,8));
    cout << "The closest prime palindrome to " << n << " is " << primePalindrome(n) << endl;

    // Time tracker
    stopTiming(start);

    return 0;
}