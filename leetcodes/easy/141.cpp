// Leetcode 141: Linked list cycle
// Original time: 3:11
// O(n) time, O(1) space

#include "../startTiming.cpp"
#include "../stopTiming.cpp"
#include "/home/thomas/Documents/RSP/RSP-Data-Structure-Library/structures/unsorted_singly_linked_list.cpp"

#include <iostream>
#include <vector>
using namespace std;

bool hasCycle(LinkedList<int> *head) {
    LinkedList<int>* tortoise = head;
    LinkedList<int>* hare = head;

    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare) { return true; }
    }

    return false;
}

int main() {
    // This test case is a cycle
    LinkedList<int>* list = new LinkedList<int>(0);
    listInsert(&list,1);
    listInsert(&list,2);
    listInsert(&list,3);
    listInsert(&list,4);
    listInsert(&list,5);

    LinkedList<int>* end = listSearch(list,0);
    end->next = list;

    // Time tracker
    auto start = startTiming();

    cout << "Output: " << hasCycle(list) << endl;

    // Time tracker
    stopTiming(start);

}