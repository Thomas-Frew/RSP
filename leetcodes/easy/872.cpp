// Leetcode 872: Leaf-similar trees
// Original time: 5:16
// O(T1 + T2) time, O(T1 + T2) space

#include "../startTiming.cpp"
#include "../stopTiming.cpp"
#include "/home/thomas/Documents/RSP/RSP-Data-Structure-Library/structures/binary_search_tree.cpp"

#include <iostream>
#include <vector>
using namespace std;


void generateSequence(BinarySearchTree<int>* t, vector<int>& seq) {
    if (t == nullptr) { return; }
    if (t->left == nullptr && t->right == nullptr) { seq.push_back(t->value); }

    generateSequence(t->left, seq);
    generateSequence(t->right, seq);
}

bool leafSimular(BinarySearchTree<int>* t1, BinarySearchTree<int>* t2) {
    vector<int> seq1;
    vector<int> seq2;

    generateSequence(t1, seq1);
    generateSequence(t2, seq2);

    return seq1 == seq2;
}

int main() {
    BinarySearchTree<int>* t1 = new BinarySearchTree<int>(0,0);
    insert_leaf(&t1,2,2);
    insert_leaf(&t1,-2,-2);

    BinarySearchTree<int>* t2= new BinarySearchTree<int>(3,3);
    insert_leaf(&t2,2,2);
    insert_leaf(&t2,-2,-2);

    cout << "Output: " << leafSimular(t1,t2) << endl;
}