#include <iostream>
using namespace std;

class IntList {
    public:
        int value;
        IntList* next = NULL;

        void insert(IntList**l, int val);
        IntList* search(IntList* e, int s);
        void print(IntList* e);

        IntList* predecessor_list(IntList* e, int s);
        void delete_node(IntList** e, int d);
};

void IntList::insert(IntList **list, int value) {
    IntList* p;
    /* temporary pointer */
    p = new IntList;
    p->value = value;
    p->next = *list;
    *list = p;
}

IntList* IntList::search(IntList* element, int s) {
        if (element->value == s) return element;
        return search(element->next, s);
}

void IntList::print(IntList *element) {
    if (element->next != NULL) {
        cout << element->value << " ";
        print(element->next);
    }
}

IntList* IntList::predecessor_list(IntList *element, int s) {
    if (element == NULL || element->next == NULL) {
        return NULL;
    }

    if ((element->next)->value == s) return element;
    else predecessor_list(element->next, s);
}

void IntList::delete_node(IntList** list, int d) {
    IntList* deleted_node = (*list)->search(*list, d);

    if (deleted_node != NULL) {
        IntList* predecessor = (*list)->predecessor_list(*list, d);

        if (predecessor == NULL) {
            *list = deleted_node->next;
        } else {
            predecessor->next = deleted_node->next;
        }
        delete deleted_node;
    }
}

int main() {
    IntList* list = new IntList;
    list->insert(&list, 1);
    list->insert(&list, 2);
    list->insert(&list, 3);
    list->insert(&list, 4);
    list->insert(&list, 5);

    list->print(list);

    cout << endl;
    cout << list->search(list, 2) << endl;
    cout << list->search(list, 1) << endl;

    list->delete_node(&list, 3);
    list->print(list);
    cout << endl;

    list->delete_node(&list, 1);
    list->print(list);
    cout << endl;

    list->delete_node(&list, 5);
    list->print(list);
    cout << endl;

    return 0;
}