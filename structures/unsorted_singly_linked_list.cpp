#include <iostream>
#include <string>
using namespace std;

template <typename T>
class LinkedList {
    public:
        T value;
        LinkedList<T>* next = nullptr;

        LinkedList(T v): value(v) {}
};

// Insert the new element at the start of a linked list
template <typename T>
void listInsert(LinkedList<T>** list, T value) {
    LinkedList<T>* inserted = new LinkedList<T>(value);
    inserted->next = *list;
    *list = inserted;
}

template <typename T>
void listPrint(LinkedList<T>* elem) {
    cout << elem->value << endl;
    if (elem->next != nullptr) listPrint(elem->next);
}

template <typename T>
void listPrintInline(LinkedList<T>* elem) {
    while (elem != nullptr) {
        cout << elem->value << " ";
        elem = elem->next;
    }
}

template <typename T>
LinkedList<T>* listSearch(LinkedList<T>* elem, T search) {
    if (elem->value == search) return elem;
    else if (elem-> next != nullptr) return listSearch(elem->next, search);
    else return nullptr;
}
template <typename T>
LinkedList<T>* listPredecessor(LinkedList<T>* elem, T search) {
    if ((elem->next)->value == search) return elem;
    else if (elem->next->next != nullptr) return listPredecessor(elem->next, search);
    return nullptr;
}

template <typename T>
void listDelete(LinkedList<T>** list, LinkedList<T>* deleted) {
    LinkedList<T>* pred = listPredecessor(*list, deleted->value);

    if (pred != nullptr) {
        pred->next = deleted->next;
    } else {
        *list = deleted->next;
    }
    delete deleted;
}

/* Structure Driver
int main() {
    // Insert test
    LinkedList<string>* list = new LinkedList<string>("Tom");
    listInsert(&list, (string)"Myles");
    listInsert(&list, (string)"Marwan");
    listInsert(&list, (string)"Tanya");

    // Print test
    listPrint(list);
    listPrintInline(list);

    // Search test
    cout << endl;
    LinkedList<string>* tomPointer = listSearch(list, (string)"Tom");
    LinkedList<string>* tanyaPointer = listSearch(list, (string)"Tanya");
    cout << tomPointer->value << " and " << tanyaPointer->value << endl;

    // Predecessor test
    cout << endl;
    LinkedList<string>* tomPred = listPredecessor(list, (string)"Tom");
    LinkedList<string>* marwanPred = listPredecessor(list, (string)"Marwan");
    cout << tomPred->value << " and " << marwanPred->value << endl;

    // Delete test
    cout << endl;
    listDelete(&list, tanyaPointer);
    listDelete(&list, tomPointer);

    listPrint(list);

    return 0;
} */