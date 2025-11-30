/**
 * Exercise 35: AVL Tree (Self-Balancing BST)
 * Difficulty: ***** (5/5)
 * 
 * Implement an AVL tree, a self-balancing binary search tree where the heights
 * of the two child subtrees of any node differ by at most one.
 * 
 * Operations to implement:
 * - Insert(key): Insert a new key and rebalance if needed
 * - Delete(key): Remove a key and rebalance if needed
 * - Search(key): Check if a key exists in the tree
 * - Inorder(): Print inorder traversal (sorted order)
 * 
 * AVL trees maintain O(log n) height through rotations:
 * - Left rotation, Right rotation
 * - Left-Right rotation, Right-Left rotation
 * 
 * Input:
 * - First line: number of operations N
 * - Next N lines: operation commands
 *   - "insert X": insert key X
 *   - "delete X": delete key X
 *   - "search X": search for key X
 *   - "inorder": print inorder traversal
 * 
 * Output:
 * - For "search X": print "Found" or "Not found"
 * - For "inorder": print all keys in sorted order, space-separated
 *   (or "Empty tree" if tree is empty)
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
    
    // TODO: Implement getHeight(node): return height of node (0 for nullptr)
    
    // TODO: Implement getBalance(node): return balance factor (left height - right height)
    
    // TODO: Implement updateHeight(node): update height based on children
    
    // TODO: Implement rightRotate(y): perform right rotation
    
    // TODO: Implement leftRotate(x): perform left rotation
    
    // TODO: Implement insertHelper(node, key): recursive insert with balancing
    
    // TODO: Implement deleteHelper(node, key): recursive delete with balancing
    
    // TODO: Implement searchHelper(node, key): recursive search
    
    // TODO: Implement inorderHelper(node): recursive inorder traversal
    
    // TODO: Implement getMinValueNode(node): find node with minimum key
    
public:
    AVLTree() : root(nullptr) {}
    
    // TODO: Implement public methods: insert, remove, search, inorder
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    AVLTree tree;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        // TODO: Handle operations based on command
    }
    
    return 0;
}
