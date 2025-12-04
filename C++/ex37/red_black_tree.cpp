/**
 * Exercise 37: Red-Black Tree
 * Difficulty: ***** (5/5)
 * 
 * Implement a Red-Black Tree, a self-balancing binary search tree with the
 * following properties:
 * 1. Every node is either red or black
 * 2. Root is always black
 * 3. All leaves (nullptr) are black
 * 4. Red nodes cannot have red children
 * 5. Every path from root to leaf has the same number of black nodes
 * 
 * Operations:
 * - Insert: Add a new key and rebalance with rotations and recoloring
 * - Search: Check if a key exists
 * - Inorder: Print inorder traversal showing colors
 * 
 * Input:
 * - First line: number of operations N
 * - Next N lines: operation commands
 *   - "insert X": insert key X
 *   - "search X": search for key X
 *   - "inorder": print inorder traversal with colors
 * 
 * Output:
 * - For "search X": print "Found" or "Not found"
 * - For "inorder": print keys with color (e.g., "5(B) 10(R) 15(B)")
 *   (or "Empty tree" if tree is empty)
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
    
    // TODO: Implement leftRotate(x): perform left rotation
    
    // TODO: Implement rightRotate(y): perform right rotation
    
    // TODO: Implement fixViolation(z): fix red-black violations after insertion
    
    // TODO: Implement insertHelper(key): insert and fix violations
    
    // TODO: Implement searchHelper(node, key): recursive search
    
    // TODO: Implement inorderHelper(node): recursive inorder with colors
    
public:
    RedBlackTree() : root(nullptr) {}
    
    // TODO: Implement public methods: insert, search, inorder
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    RedBlackTree tree;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        // TODO: Handle operations based on command
    }
    
    return 0;
}
