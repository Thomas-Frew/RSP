// Leetcode 872: Leaf-similar trees
// Original time: 4:09
// O(n) time, O(1) space

// The trick here was knowing that the whole string is balanced, and that a balancing of the string indicates a new substring being created.
// It's important to consider accumulative systems and greedy heuristics.

#include "../startTiming.cpp"
#include "../stopTiming.cpp"
#include "../balancedString.cpp"
    
int balancedStringSplit(string s) {
    int count = 0;
    int substringCount = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'L') { count++; }
        else { count--; }

        if (count == 0) { substringCount++; }
    }

    return substringCount;
}

int main() {
    // Generate random test case
    string test = balancedString(10,'L','R');
    cout << "Input: " << test << endl;

    auto start = startTiming();
    cout << "You can make " << balancedStringSplit(test) << " balanced substrings." << endl;
    stopTiming(start);

    return 0;
}