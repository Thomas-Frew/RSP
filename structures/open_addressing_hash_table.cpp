#include <iostream>
#include <string>
#include <math.h>
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

class HashTable {
    public:
        string* items;
        int MAX_SIZE;
        int n;

        HashTable(int m): MAX_SIZE(m) {
            items = new string[MAX_SIZE];
        }
};

void tableInsert(HashTable* table, string item) {
    int index = hashString(item, table->MAX_SIZE);
    int checks = 0;

    while (table->items[index] != "" && checks < table->MAX_SIZE) {  
        index = index < table->MAX_SIZE ? index + 1 : 0;
        checks++;
    }

    table->items[index] = item;
}

void tablePrint(HashTable* table) {
    for (int i = 0; i < table->MAX_SIZE; i++) {
        if (table->items[i] != "") { cout << i << ": " << table->items[i] << endl; }
    }
}

string* tableSearch(HashTable* table, string search) {
    int index = hashString(search, table->MAX_SIZE);
    int checks = 0;

    while (table->items[index] != search  && checks < table->MAX_SIZE) {
        index = index < table->MAX_SIZE ? index + 1 : 0;
        checks++;
    }

    if (checks == table->MAX_SIZE) return nullptr;
    else return &(table->items[index]);
} 

int main() {
    HashTable* table = new HashTable(10);

    tableInsert(table, "TOM");
    tableInsert(table, "TANYA");
    tableInsert(table, "MYLES");
    tableInsert(table, "RAHUL");
    tableInsert(table, "GOODIE");
    tableInsert(table, "HARRIET");
    tableInsert(table, "NATALIE");
    tableInsert(table, "ANNA");
    tableInsert(table, "JOHN");
    tableInsert(table, "SAM");
    tableInsert(table, "SAM");

    tablePrint(table);

    cout << tableSearch(table, "SAM") << endl;
    cout << tableSearch(table, "ANNA") << endl;
    cout << tableSearch(table, "HELLO") << endl;

    return 0;
}
