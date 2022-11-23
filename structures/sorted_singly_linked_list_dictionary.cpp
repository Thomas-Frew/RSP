#include <string>
#include <iostream>
using namespace std;

template <typename T>
class SingleLinkedDict {
    public:
        int key;
        T value;

        SingleLinkedDict* next = nullptr;

        SingleLinkedDict(int k, T v): key(k), value(v) {}
};

template <typename T>
void insert_node(SingleLinkedDict<T>** dict, SingleLinkedDict<T>* element, int key, T value) {
    // Start of list
    if (key < element->key) {
        SingleLinkedDict<T>* inserted = new SingleLinkedDict<T>(key, value);
        *dict = inserted;
        inserted->next = element;
    // End of list
    } else if (element->next == nullptr) {
        SingleLinkedDict<T>* inserted = new SingleLinkedDict<T>(key, value);
        element->next = inserted;
    } else if (key < element->next->key) {
        SingleLinkedDict<T>* inserted = new SingleLinkedDict<T>(key, value);
        inserted->next = element->next;
        element->next = inserted;
    } else {
        insert_node(dict, element->next, key, value);
    }
}

template <typename T>
void delete_node(SingleLinkedDict<T>** dict, SingleLinkedDict<T>* deleted) {
    SingleLinkedDict<T>* pred = dict_predecessor(*dict, deleted);

    if (pred != nullptr) {
        pred->next = deleted->next;
    } else {
        *dict = deleted->next;
    }

    delete deleted;
}

template <typename T>
void print_dict(SingleLinkedDict<T>* element) {
    cout << element->key << ": " << element->value << endl;
    if (element->next != nullptr) print_dict(element->next);
}

template <typename T>
SingleLinkedDict<T>* dict_search(SingleLinkedDict<T>* element, int key) {
    if (element->key == key) return element;
    else if (element->next != nullptr) dict_search(element->next, key);
    else return nullptr;
}

template<typename T>
SingleLinkedDict<T>* dict_min(SingleLinkedDict<T>* dict) {
    return dict; // The minimum item is always at the front
}

// This is possible in O(1) if we maintain a pointer to the end of the dictionary. We will use an alternate method.
template<typename T>
SingleLinkedDict<T>* dict_max(SingleLinkedDict<T>* element) {
    if (element->next != nullptr) dict_max(element->next);
    else return element;
}

template<typename T>
SingleLinkedDict<T>* dict_predecessor(SingleLinkedDict<T>* current, SingleLinkedDict<T>* search) {
    if (current->next == search) return current;
    else if (current->next != nullptr) dict_predecessor(current->next, search);
    else return nullptr;
}

template<typename T>
SingleLinkedDict<T>* dict_successor(SingleLinkedDict<T>* element) {
    return element->next;
}


// Structure driver
int main() {
    // Insertion test
    SingleLinkedDict<char>* dict = new SingleLinkedDict<char>(3,'L');
    insert_node(&dict, dict, 5, 'S');
    insert_node(&dict, dict, 2, 'Y');
    insert_node(&dict, dict, 4, 'E');
    insert_node(&dict, dict, 1, 'M');

    // Print test
    print_dict(dict);

    // Search test
    cout << endl;
    cout << dict_search(dict, 1) << endl;
    cout << dict_search(dict, 5) << endl;

    // Minimum and maximum test
    cout << endl;
    cout << "Minimum: " << dict_min(dict)->value << endl;
    cout << "Maximum: " << dict_max(dict)->value << endl;
    
    // Predecessor and successor test
    cout << endl;
    cout << "Minimum successor: " << dict_successor(dict_min(dict))->value << endl;
    cout << "Maximum predecessor: " << dict_predecessor(dict, dict_max(dict))->value << endl;

    // Delete test
    cout << endl;
    delete_node(&dict, dict_min(dict));
    delete_node(&dict, dict_search(dict,3));
    delete_node(&dict, dict_max(dict));
    print_dict(dict);

    return 0;
}
