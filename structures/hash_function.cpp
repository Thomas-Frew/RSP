#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    string test = "B";
    int len = test.length();
    int value = 0;

    for (int i = 0; i < len; i++) {
        value += pow(26, (len-i-1)) * ((int)test[i]-65);
    }

    cout << value << endl;

    return 0;
}