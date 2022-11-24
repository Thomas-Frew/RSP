#include <iostream>
#include <string>
#include <math.h>
#include "unsorted_singly_linked_list.cpp"
using namespace std;

int hashString (string input, int size) {
    int len = input.length();
    int value = 0;

    for (int i = 0; i < len; i++) {
        value += pow(26, (len-i-1)) * ((int)input[i]-65);
    }

    int index = value % size;

    return index;
}

class StringHashTable {
    public:
        int size;
        int count;
        LinkedList<string>** items;

        StringHashTable(): StringHashTable(0) {}

        StringHashTable(int s) {
            size = s;
            count = 0;
            items = new LinkedList<string>*[size];          
        }
};

void tableInsert(StringHashTable* table, string input) {
    int index = hashString(input, table->size);
    listInsert(&table->items[index], input);
}

void tablePrint(StringHashTable* table, int i = 0) {
    if (i < table->size) {
        if (table->items[i] != nullptr) {
            cout << i << ":\t";
            listPrintInline(table->items[i]);
            cout << endl;
        }
        tablePrint(table, ++i);
    }
}

LinkedList<string>* tableSearch(StringHashTable* table, string search) {
    int index = hashString(search, table->size);
    return listSearch(table->items[index], search);
}

void tableDelete(StringHashTable* table, LinkedList<string>* deleted) {
    int index = hashString(deleted->value, table->size);
    listDelete(&table->items[index], deleted);
}


int main() {
    StringHashTable* table = new StringHashTable(997);

    // Insert test
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < 26; k++) {
                string str;
                str += (65+i);
                str += (65+j);
                str += (65+k);
                tableInsert(table, str);
            }
        }
    }

    // Print test
    tablePrint(table);

    // Search test
    cout << tableSearch(table, "TOM") << endl;
    cout << tableSearch(table, "SAM") << endl;

    // Delete test
    tableDelete(table, tableSearch(table, "ZBW"));
    tablePrint(table);

    return 0;
}