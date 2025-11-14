#include <bits/stdc++.h>
using namespace std;

/**
 * Exercise 15: Binary Search Tree
 * Difficulty: ***** (5/5)
 * 
 * Implement a binary search tree with insert and search operations.
 * 
 * Input:
 * - Commands: "insert <value>", "search <value>", or "exit"
 * 
 * Output:
 * - For search: print "found" if value exists, "not found" otherwise
 */

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    
    void InsertRecursive(Node*& node, int value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->value) {
            InsertRecursive(node->left, value);
        } else if (value > node->value) {
            InsertRecursive(node->right, value);
        }
    }
    
    bool SearchRecursive(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (value == node->value) {
            return true;
        } else if (value < node->value) {
            return SearchRecursive(node->left, value);
        } else {
            return SearchRecursive(node->right, value);
        }
    }
    
    void DeleteRecursive(Node*& node) {
        if (node == nullptr) {
            return;
        }
        DeleteRecursive(node->left);
        DeleteRecursive(node->right);
        delete node;
        node = nullptr;
    }
    
public:
    BST() : root(nullptr) {}
    
    ~BST() {
        DeleteRecursive(root);
    }
    
    void Insert(int value) {
        InsertRecursive(root, value);
    }
    
    bool Search(int value) {
        return SearchRecursive(root, value);
    }
};

int main() {
    BST bst;
    string command;
    
    while (true) {
        cin >> command;
        
        if (command == "insert") {
            int value;
            cin >> value;
            bst.Insert(value);
        } else if (command == "search") {
            int value;
            cin >> value;
            if (bst.Search(value)) {
                cout << "found" << endl;
            } else {
                cout << "not found" << endl;
            }
        } else if (command == "exit") {
            break;
        }
    }
    
    return 0;
}
