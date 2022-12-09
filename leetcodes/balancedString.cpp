#include <random>
#include <time.h>
using namespace std;

/// @brief Creates a random, balanced string of two unique characters.
/// @param size The size of the string (always even)
/// @param left The first character to choose from 
/// @param right The second character to choose from
/// @return The balanced string
string balancedString(int size, char left, char right) {
    string balancedString = "";
    int leftCount = size/2;
    int rightCount = size/2;

    srand(time(NULL));

    while (leftCount != 0 || rightCount != 0) {
        if (leftCount == 0) {
            balancedString += right;
            rightCount--;
        } else if (rightCount == 0) { 
            balancedString += left;
            leftCount--; 
        } else {
            int choice = random() % 2;

            if (choice == 0) {
                balancedString += right;
                rightCount--;
            } else {
                balancedString += left;
                leftCount--; 
            }
        }
    }
    
    return balancedString;

}