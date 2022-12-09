// Leetcode 2087: Minimum robot homecoming
// Original time: 2:00:00 (failed)
// O(r+c) time, O(1) space

// The trick was this problem was identifying that all paths have the same cost.
// It is crucial to funny understand and test the situation before attempting to produce an algorithm.

#include "../randomIntVector.cpp"
#include "../vectorPrint.cpp"
#include "../startTiming.cpp"
#include "../stopTiming.cpp"

#include <vector>
using namespace std;

int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {

    int destRow = homePos[0];
    int destCol = homePos[1];

    int row = startPos[0];
    int col = startPos[1];

    int cost = 0;

    if (row < destRow) {
        while (row != destRow) {
            cost += rowCosts[++row];
        }
    } else {
        while (row != destRow) {
            cost += rowCosts[--row];
        }
    }

    if (col < destCol) {
        while (col != destCol) {
            cost += colCosts[++col];
        }
    } else {
        while (col != destCol) {
            cost += colCosts[--col];
        }
    }

    return cost;
}

int main() {
    srand(time(NULL));

    vector<int> startPos = {0,0};
    vector<int> homePos = {5,5};

    vector<int> rowCosts = randomIntVector(5,0,10);
    vector<int> colCosts = randomIntVector(5,0,10);

    cout << "Row costs: ";
    vectorPrint(rowCosts);
    cout << endl;

    cout << "Column costs: ";
    vectorPrint(colCosts);
    cout << endl;

    cout << "Minumum homecoming: " << minCost(startPos,homePos,rowCosts,colCosts) << endl;
};