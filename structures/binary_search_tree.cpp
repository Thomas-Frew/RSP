#include <string>
#include <iostream>
using namespace std;

template <typename T>
class BinarySearchTree {
    public:
        int key;
        T value;

        BinarySearchTree<T>* left = nullptr;
        BinarySearchTree<T>* right = nullptr;
        BinarySearchTree<T>* parent = nullptr;

        BinarySearchTree(int k, T v): key(k), value(v) {}
};

template <typename T>
void insert_leaf(BinarySearchTree<T>** element, int key, T value) {
    if (*element == nullptr) {
        BinarySearchTree<T>* inserted = new BinarySearchTree<T>(key, value);
        *element = inserted;
    } else if (key < (*element)->key) {
        insert_leaf(&(*element)->left, key, value);
    } else {
        insert_leaf(&(*element)->right, key, value);
    }
}

template <typename T>
void print_tree(BinarySearchTree<T>* element) {
    if (element != nullptr) {
        print_tree(element->left);
        cout << element->key << ":\t" << element->value << endl;
        print_tree(element->right);
    }
}

template <typename T>
void print_tree_with_depth(BinarySearchTree<T>* element, int depth = 0) {
    if (element != nullptr) {
        depth++;
        print_tree_with_depth(element->left, depth);
        cout << element->key << ":\t" << element->value << "\t(" << depth << ")" << endl;
        print_tree_with_depth(element->right, depth);
    }
}

template <typename T>
BinarySearchTree<T>* search_tree(BinarySearchTree<T>* element, int key) {
    if (element == nullptr) return nullptr;
    if (element->key == key) return element;
    if (key < element->key) return search_tree(element->left, key);
    else return search_tree(element->right, key);
}

template <typename T>
BinarySearchTree<T>* tree_min(BinarySearchTree<T>* element) {
    if (element->left != nullptr) tree_min(element->left);
    else return element;
}

template <typename T>
BinarySearchTree<T>* tree_max(BinarySearchTree<T>* element) {
    if (element->right != nullptr) tree_max(element->right);
    else return element;
}

// We begin count at -1 so the root element is not counted
template <typename T>
int tree_children(BinarySearchTree<T>* element, int count = -1) {
    if (element != nullptr) {
        count++;
        if (element->left != nullptr) {
            count = tree_children(element->left, count);
        }
        if (element->right != nullptr) {
            count = tree_children(element->right, count);
        }
        return count;
    }
}

/* Deletion TBA
template <typename T>
void delete_leaf(BinarySearchTree<T>* tree, BinarySearchTree<T>* deleted) {
    BinarySearchTree<T>* parent = tree_parent(tree, deleted->key);

    cout << parent->value << endl;

    // If the node has no children...
    if (deleted->left == nullptr && deleted->right == nullptr) {
        if (deleted->key < parent->key) parent->left = nullptr; // Child left of parent
        else parent->right = nullptr; // Child right of parent
    }
    // If the deleted node has a child on the left...
    else if (deleted->right == nullptr) {
        if (deleted->key < parent->key) parent->left = deleted->left; // Child left of parent
        else parent->right = deleted->left; // Child right of parent
    }
    // If the deleted node has a child on the right...
    else if (deleted->left == nullptr) {
        if (deleted->key < parent->key) parent->left = deleted->right; // Child left of parent
        else parent->right = deleted->right; // Child right of parent
    }
    // If the deleted node has two children...
    else {
        BinarySearchTree<T>* replacement = tree_min(deleted->right);
        delete_leaf(deleted, replacement);

        deleted->key = replacement->key;
        deleted->value = replacement->value;
    }
} */


/* Structure driver
int main() {
    // Insertion test
    BinarySearchTree<char>* tree = new BinarySearchTree<char>(0, 'T');
    insert_leaf(&tree, 10, 'M');
    insert_leaf(&tree, -1, 'S');
    insert_leaf(&tree, 5, 'Y');
    insert_leaf(&tree, 6, 'J');
    insert_leaf(&tree, 3, 'N');

    // Print tests
    cout << endl;
    print_tree(tree);

    cout << endl;
    print_tree_with_depth(tree);

    // Search tests
    cout << endl;
    cout << search_tree(tree, 0) << endl;
    cout << search_tree(tree, -1) << endl;
    cout << search_tree(tree, 3) << endl;
    
    // Minimum and maximum tests
    cout << endl;
    cout << "Minimum: " << tree_min(tree)->value << endl;
    cout << "Maximum: " << tree_max(tree)->value << endl;

    // Children count tests
    cout << endl;
    cout << "Children of root: " << tree_children(tree) << endl;
    cout << "Children of min: " << tree_children(tree_min(tree)) << endl;
    cout << "Children of max: " << tree_children(tree_max(tree)) << endl;

    // Deletion TBA

    return 0;
}*/