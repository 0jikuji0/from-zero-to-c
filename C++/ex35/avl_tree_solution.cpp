/**
 * Exercise 35: AVL Tree (Self-Balancing BST)
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing AVL tree with rotations for self-balancing.
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;
    
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }
    
    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }
    
    void updateHeight(Node* node) {
        if (node) {
            node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        }
    }
    
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        
        x->right = y;
        y->left = T2;
        
        updateHeight(y);
        updateHeight(x);
        
        return x;
    }
    
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        
        y->left = x;
        x->right = T2;
        
        updateHeight(x);
        updateHeight(y);
        
        return y;
    }
    
    Node* insertHelper(Node* node, int key) {
        if (!node) {
            return new Node(key);
        }
        
        if (key < node->key) {
            node->left = insertHelper(node->left, key);
        } else if (key > node->key) {
            node->right = insertHelper(node->right, key);
        } else {
            return node; // Duplicate keys not allowed
        }
        
        updateHeight(node);
        
        int balance = getBalance(node);
        
        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            return rightRotate(node);
        }
        
        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            return leftRotate(node);
        }
        
        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    Node* getMinValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) {
            current = current->left;
        }
        return current;
    }
    
    Node* deleteHelper(Node* node, int key) {
        if (!node) {
            return node;
        }
        
        if (key < node->key) {
            node->left = deleteHelper(node->left, key);
        } else if (key > node->key) {
            node->right = deleteHelper(node->right, key);
        } else {
            // Node with only one child or no child
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;
                
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                // Node with two children
                Node* temp = getMinValueNode(node->right);
                node->key = temp->key;
                node->right = deleteHelper(node->right, temp->key);
            }
        }
        
        if (!node) {
            return node;
        }
        
        updateHeight(node);
        
        int balance = getBalance(node);
        
        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }
        
        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        
        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }
        
        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    bool searchHelper(Node* node, int key) {
        if (!node) {
            return false;
        }
        
        if (key == node->key) {
            return true;
        } else if (key < node->key) {
            return searchHelper(node->left, key);
        } else {
            return searchHelper(node->right, key);
        }
    }
    
    void inorderHelper(Node* node, bool& first) {
        if (node) {
            inorderHelper(node->left, first);
            if (!first) cout << " ";
            cout << node->key;
            first = false;
            inorderHelper(node->right, first);
        }
    }
    
public:
    AVLTree() : root(nullptr) {}
    
    void insert(int key) {
        root = insertHelper(root, key);
    }
    
    void remove(int key) {
        root = deleteHelper(root, key);
    }
    
    bool search(int key) {
        return searchHelper(root, key);
    }
    
    void inorder() {
        if (!root) {
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
    
    AVLTree tree;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "insert") {
            int key;
            cin >> key;
            tree.insert(key);
        } else if (operation == "delete") {
            int key;
            cin >> key;
            tree.remove(key);
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
