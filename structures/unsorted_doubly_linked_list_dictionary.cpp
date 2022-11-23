#include <string>
#include <iostream>
using namespace std;

template <typename T>
class DoubleLinkedDict {
    public:
        int key;
        T value;

        DoubleLinkedDict(int k, T v): key(k), value(v) {}

        DoubleLinkedDict<T>* prev = nullptr;
        DoubleLinkedDict<T>* next = nullptr;
};


// Insert
template <typename T>
void insert_node(DoubleLinkedDict<T>** dict, int key, T value) {
    DoubleLinkedDict<T>* node = new DoubleLinkedDict<T>(key,value);

    node->next = *dict;
    (*dict)->prev = node;

    *dict = node;
}

// Delete
template <typename T>
void delete_node(DoubleLinkedDict<T>** dict, DoubleLinkedDict<T>* deleted) {
    if (deleted->next != nullptr) {
        (deleted->next)->prev = deleted->prev;
    }
    if (deleted->prev != nullptr) {
        (deleted->prev)->next = deleted->next;
    } else {
        *dict = deleted->next;
    }
}

// Minimum
template<typename T>
DoubleLinkedDict<T>* dict_min(DoubleLinkedDict<T>* dict, DoubleLinkedDict<T>* min) {
    min = dict->key < min->key ? dict : min;
    if (dict->next != nullptr) dict_min(dict->next, min);
    else return min;
}

// Maximum
template<typename T>
DoubleLinkedDict<T>* dict_max(DoubleLinkedDict<T>* dict, DoubleLinkedDict<T>* max) {
    max = dict->key > max->key ? dict : max;
    if (dict->next != nullptr) dict_max(dict->next, max);
    else return max;
}

// Search
template<typename T>
DoubleLinkedDict<T>* dict_search(DoubleLinkedDict<T>* dict, int key) {
    if (dict->key == key) return dict;
    else if (dict->next != nullptr) dict_search(dict->next, key);
    else return nullptr;
}

// Predecessor
template<typename T>
DoubleLinkedDict<T>* dict_predecessor(DoubleLinkedDict<T>* dict, int key) {
    DoubleLinkedDict<T>* focus = dict_search(dict, key);
    return focus->prev;
} 

// Successor
template<typename T>
DoubleLinkedDict<T>* dict_successor(DoubleLinkedDict<T>* dict, int key) {
    DoubleLinkedDict<T>* focus = dict_search(dict, key);
    return focus->next;
} 


template <typename T>
void print_dict(DoubleLinkedDict<T>* dict) {
    cout <<  dict->key << ": " << dict->value << endl;
    if (dict->next != nullptr) print_dict(dict->next);
}

// Structure driver
int main() {
    // Initialisation
    DoubleLinkedDict<char>* dict = new DoubleLinkedDict<char>(1,'S');

    // Insert test
    insert_node(&dict,2,'E');
    insert_node(&dict,3,'L');
    insert_node(&dict,4,'Y');
    insert_node(&dict,5,'M');

    // Print test
    print_dict(dict);

    // Min and max test
    cout << endl;
    cout << dict_min(dict,dict)->value << endl;
    cout << dict_max(dict,dict)->value << endl;
    
    // Search test
    cout << endl;
    cout << dict_search(dict,5)->value << endl;
    cout << dict_search(dict,3)->value << endl;   
    cout << dict_search(dict,1)->value << endl;

    // Predessor and successor test
    cout << endl;
    cout << dict_predecessor(dict,4)->value << endl;
    cout << dict_predecessor(dict,2)->value << endl;

    cout << endl;
    cout << dict_successor(dict,5)->value << endl;
    cout << dict_successor(dict,3)->value << endl;

    // Delete test
    cout << endl;
    delete_node(&dict, dict_search(dict,5));
    print_dict(dict);

    cout << endl;
    delete_node(&dict, dict_search(dict,2));
    print_dict(dict);
    
    return 0;
}