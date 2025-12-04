/**
 * Exercise 37: Red-Black Tree
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Red-Black Tree with insertions and rebalancing.
 */

#include <iostream>
#include <string>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int key;
    Color color;
    Node *left, *right, *parent;
    
    Node(int k) : key(k), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;
    
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        
        if (y->left != nullptr)
            y->left->parent = x;
        
        y->parent = x->parent;
        
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        
        y->left = x;
        x->parent = y;
    }
    
    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        
        if (x->right != nullptr)
            x->right->parent = y;
        
        x->parent = y->parent;
        
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        
        x->right = y;
        y->parent = x;
    }
    
    void fixViolation(Node* z) {
        while (z != root && z->parent->color == RED) {
            Node* parent = z->parent;
            Node* grandparent = parent->parent;
            
            if (parent == grandparent->left) {
                Node* uncle = grandparent->right;
                
                // Case 1: Uncle is red
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    z = grandparent;
                } else {
                    // Case 2: z is right child
                    if (z == parent->right) {
                        leftRotate(parent);
                        z = parent;
                        parent = z->parent;
                    }
                    // Case 3: z is left child
                    rightRotate(grandparent);
                    swap(parent->color, grandparent->color);
                    z = parent;
                }
            } else {
                Node* uncle = grandparent->left;
                
                // Case 1: Uncle is red
                if (uncle != nullptr && uncle->color == RED) {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    z = grandparent;
                } else {
                    // Case 2: z is left child
                    if (z == parent->left) {
                        rightRotate(parent);
                        z = parent;
                        parent = z->parent;
                    }
                    // Case 3: z is right child
                    leftRotate(grandparent);
                    swap(parent->color, grandparent->color);
                    z = parent;
                }
            }
        }
        root->color = BLACK;
    }
    
    bool searchHelper(Node* node, int key) {
        if (node == nullptr)
            return false;
        
        if (key == node->key)
            return true;
        else if (key < node->key)
            return searchHelper(node->left, key);
        else
            return searchHelper(node->right, key);
    }
    
    void inorderHelper(Node* node, bool& first) {
        if (node != nullptr) {
            inorderHelper(node->left, first);
            if (!first) cout << " ";
            cout << node->key << "(" << (node->color == RED ? "R" : "B") << ")";
            first = false;
            inorderHelper(node->right, first);
        }
    }
    
public:
    RedBlackTree() : root(nullptr) {}
    
    void insert(int key) {
        Node* z = new Node(key);
        Node* y = nullptr;
        Node* x = root;
        
        while (x != nullptr) {
            y = x;
            if (z->key < x->key)
                x = x->left;
            else if (z->key > x->key)
                x = x->right;
            else {
                delete z; // Duplicate key
                return;
            }
        }
        
        z->parent = y;
        
        if (y == nullptr)
            root = z;
        else if (z->key < y->key)
            y->left = z;
        else
            y->right = z;
        
        fixViolation(z);
    }
    
    bool search(int key) {
        return searchHelper(root, key);
    }
    
    void inorder() {
        if (root == nullptr) {
            cout << "Empty tree" << endl;
        } else {
            bool first = true;
            inorderHelper(root, first);
            cout << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    RedBlackTree tree;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "insert") {
            int key;
            cin >> key;
            tree.insert(key);
        } else if (operation == "search") {
            int key;
            cin >> key;
            cout << (tree.search(key) ? "Found" : "Not found") << endl;
        } else if (operation == "inorder") {
            tree.inorder();
        }
    }
    
    return 0;
}
