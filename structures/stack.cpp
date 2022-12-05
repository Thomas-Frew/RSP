#include <iostream>
using namespace std;

template <typename T>
class Stack {
    public:
        T value;
        Stack<T>* next;

        Stack(): value(NULL), next(nullptr) {}
        Stack(T v): value(v), next(nullptr) {}
};

template <typename T>
void stackPush(Stack<T>** s, T value) {
    Stack<T>* inserted = new Stack<T>(value);

    inserted->next = *s;
    *s = inserted;
}


template <typename T>
Stack<T>* stackPop(Stack<T>** s) {
    Stack<T>* popped = *s;
    *s = (*s)->next;

    return popped;
}


// Structure drivers
int main() {
    // Constructor test
    Stack<char>* stack = new Stack<char>('M');

    // Push test
    stackPush(&stack, 'Y');
    stackPush(&stack, 'L');
    stackPush(&stack, 'E');
    stackPush(&stack, 'S');

    // Pop test
    cout << stackPop(&stack)->value << endl;
    cout << stackPop(&stack)->value << endl;
    cout << stackPop(&stack)->value << endl;
    cout << stackPop(&stack)->value << endl;
    cout << stackPop(&stack)->value << endl;
}