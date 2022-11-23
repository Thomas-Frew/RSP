#include <string>
#include <iostream>

using namespace std;

template <typename T>
struct Pair {
    int key;
    T value;
};

template <typename T>
class Dictionary {
    public:
        Pair<T>* dictionary;
        int size = 0;
        int max_size = 1;

        Dictionary() { dictionary = new Pair<T>[1]; }
        void insert(Pair<T> e);
        Pair<T>* search(int k);
        Pair<T>* min();
        Pair<T>* max();
        void print();

        Pair<T>* predecessor(Dictionary<T>* dict, int k);
        Pair<T>* successor(Dictionary<T>* dict, int k);

        void delete_element(Pair<T>* e);
};

template <typename T>
void Dictionary<T>::insert(Pair<T> element) {
    size++;
    if (size > max_size) {
        Pair<T>* temp = new Pair<T>[max_size*2];

        for (int i=0; i<max_size; i++) {
            temp[i] = dictionary[i];
        }

        delete dictionary;
        dictionary = temp;
        temp[size - 1] = element;

        max_size *= 2;
    } else {
        dictionary[size - 1] = element;
    }
}

template <typename T>
Pair<T>* Dictionary<T>::search(int key) {
    for (int i = 0; i < size; i++) {
        if (dictionary[i].key == key) return &dictionary[i];
    }
    return nullptr;
}

template <typename T>
void Dictionary<T>::print() {
    for (int i = 0; i < size; i++) {
        cout << dictionary[i].key << "," << dictionary[i].value << endl;
    }
}

template <typename T>
Pair<T>* Dictionary<T>::min() {
    Pair<T>* minimum = &dictionary[0];
    for (int i = 0; i < size; i++) {
        if (dictionary[i].key < minimum->key) minimum = &dictionary[i];
    }
    return minimum;
}

template <typename T>
Pair<T>* Dictionary<T>::max() {
    Pair<T>* maximum = &dictionary[0];
    for (int i = 0; i < size; i++) {
        if (dictionary[i].key > maximum->key) maximum = &dictionary[i];
    }
    return maximum;
}

template <typename T>
Pair<T>* Dictionary<T>::predecessor(Dictionary<T>* dict, int key) {
    Pair<T>* closest = dict->min();

    for (int i = 0; i < size; i++) {
        if (dictionary[i].key < key && dictionary[i].key > closest->key) closest = &dictionary[i];
    }
    return closest;
}

template <typename T>
Pair<T>* Dictionary<T>::successor(Dictionary<T>* dict, int key) {
    Pair<T>* closest = dict->max();

    for (int i = 0; i < size; i++) {
        if (dictionary[i].key > key && dictionary[i].key < closest->key) closest = &dictionary[i];
    }
    return closest;
}

template <typename T>
void Dictionary<T>::delete_element(Pair<T>* element) {
    *element = dictionary[size - 1];
    size--;
}



int main() {
    Dictionary<char> dict;

    for (int i = 0; i < 10; i++) {
        Pair<char> p = {i, (char)(65+i)};
        dict.insert(p);
    }

    dict.print();

    cout << endl;

    Pair<char>* B_pair = dict.search(9);
    dict.delete_element(B_pair);

    dict.print();

    return 0;
}