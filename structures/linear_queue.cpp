#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Queue {
    public:
        T value;
        Queue* next;

        Queue(): Queue(NULL) {}
        Queue(T v): Queue(v, nullptr) {}
        Queue(T v, Queue* n): value(v), next(n) {}
};

template <typename T>
void enqueue(Queue<T>** queue, T value) {
    Queue<T>* newItem = new Queue<T>(value);

    if ((*queue) == nullptr) {
        (*queue) = newItem;
    } else {
        Queue<T>* iterator = *queue;
    
        while(iterator->next != nullptr) {
            iterator = iterator->next;
        }
        
        iterator->next = newItem;
    }
}

template <typename T>
T dequeue(Queue<T>** queue) {
    if (*queue == nullptr) {
        cout << "Warning! No elements to dequeue.";
        return NULL;
    }

    T value = (*queue)->value;
    (*queue) = (*queue)->next;

    return value;
}

int main() {
    Queue<char>* queue = new Queue<char>('O');

    enqueue(&queue,'A');
    enqueue(&queue,'B');
    enqueue(&queue,'C');

    cout << dequeue(&queue) << endl;
    cout << dequeue(&queue) << endl;
    cout << dequeue(&queue) << endl;
    cout << dequeue(&queue) << endl;
    cout << dequeue(&queue) << endl;   
    cout << dequeue(&queue) << endl;

    enqueue(&queue,'D');
    enqueue(&queue,'E');
    enqueue(&queue,'F');

    cout << dequeue(&queue) << endl;
    cout << dequeue(&queue) << endl;   
    cout << dequeue(&queue) << endl;
    
    return 0;
}