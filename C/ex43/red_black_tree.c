/**
 * Exercise 43: Red-Black Tree
 * Difficulty: ***** (5/5)
 * 
 * Implement a Red-Black Tree, a self-balancing binary search tree with the
 * following properties:
 * 1. Every node is either red or black
 * 2. Root is always black
 * 3. All leaves (NULL) are black
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int key;
    int color;
    struct Node *left, *right, *parent;
} Node;

// TODO: Create new node with given key (initially red)

// TODO: Implement left rotation

// TODO: Implement right rotation

// TODO: Fix violations after insertion (recolor and rotate)

// TODO: Insert new key and fix tree

// TODO: Search for a key

// TODO: Print inorder traversal with colors

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    Node *root = NULL;
    
    for (int i = 0; i < n; i++) {
        char operation[10];
        scanf("%s", operation);
        
        // TODO: Handle operations based on command
    }
    
    return 0;
}
