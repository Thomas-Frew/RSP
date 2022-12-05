#include <string>
#include <cstring>
#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

class TrieNode {
    public:
        char value;
        bool wordTerminator;
        TrieNode** children;
        TrieNode* parent;

        TrieNode(): TrieNode('\0', false, nullptr) {}

        TrieNode(char v, bool t, TrieNode* p): value(v), wordTerminator(t), parent(p) {
            children = new TrieNode*[ALPHABET_SIZE];
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                children[i] = nullptr;
            }
        }
};


void trieInsert(TrieNode* t, char* word) {
    int length = strlen(word);
    TrieNode* p = t;

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';

        if (p->children[index] == nullptr) {
            p->children[index] = new TrieNode(word[i], i == length-1, p);
        }
        p = p->children[index];
    }
}

void wordPrint(TrieNode* c) {
    if (c != nullptr) {
        wordPrint(c->parent);
        cout << c->value;
    }
}

void triePrint(TrieNode* t) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        TrieNode* p = t->children[i];
        if (p != nullptr) {
            if (p->wordTerminator) {
                wordPrint(p);
                cout << endl;
            } else {
                triePrint(p);
            }
        }
    }
} 

TrieNode* trieSearch(TrieNode* t, char* word) {
    int length = strlen(word);
    TrieNode* p = t;

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (p->children[index] != nullptr) {
            p = p->children[index];
        } else {
            return nullptr;
        }
    }

    return p;
}

int main() {
    // Constructor test
    TrieNode* trie = new TrieNode();

    // Insert test
    trieInsert(trie, "cat");
    trieInsert(trie, "car");
    trieInsert(trie, "chair");
    trieInsert(trie, "rat");

    // Print test
    triePrint(trie);

    // Search test
    cout << endl;
    cout << trieSearch(trie, "rat") << endl;
    cout << trieSearch(trie, "ran") << endl;
    

    return 0;
}