#include <iostream>
using namespace std;

template <typename T>
class ArrayList {
    public:
        T* items;
        int size;
        int maxSize;

        ArrayList(): size(0), maxSize(1) {
            items = new T[size];
        }

    private:
        ~ArrayList() { delete items; }
};


template <typename T>
void arrayListInsert(ArrayList<T>* al, T item) {
    if (al->size >= al->maxSize) {
        al->maxSize *= 2;
        T* temp = new T[al->maxSize];

        for (int i = 0; i < al->size; i++) {
            temp[i] = al->items[i];
        }

        delete al->items;
        al->items = temp;
    }

    al->items[al->size] = item;
    al->size++;
}

template <typename T>
void arrayListPrint(ArrayList<T>* al) {
    for (int i = 0; i < al->size; i++) {
        cout << al->items[i] << " ";
    }
}

int main() {
    ArrayList<char>* arrayList = new ArrayList<char>();

    arrayListInsert(arrayList, 'A');
    arrayListInsert(arrayList, 'B');
    arrayListInsert(arrayList, 'C');
    arrayListInsert(arrayList, 'H');
    arrayListInsert(arrayList, 'E');
    arrayListInsert(arrayList, 'F');

    arrayListPrint(arrayList);

    return 0;
}