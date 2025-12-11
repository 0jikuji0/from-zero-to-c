/**
 * Exercise 48: Cartesian Tree
 * Difficulty: ***** (5/5)
 * 
 * Implement a Cartesian Tree, a binary tree derived from a sequence of numbers.
 * It satisfies both:
 * 1. Heap property: each parent is smaller (min) than its children
 * 2. BST property: inorder traversal gives original sequence
 * 
 * Applications:
 * - Range Minimum Query (RMQ) in O(1) after O(n) preprocessing
 * - Finding the nearest smaller element in a sequence
 * - Converting between sequences and trees
 * 
 * Operations:
 * - Build(arr): Build Cartesian tree from array in O(n) time using stack
 * - RangeMin(l, r): Query minimum in range [l, r]
 * - Inorder(): Print inorder traversal
 * 
 * Input:
 * - First line: size of array N
 * - Second line: N space-separated integers
 * - Third line: number of operations Q
 * - Next Q lines: operation commands
 *   - "min L R": find minimum in range [L, R] (0-indexed)
 *   - "inorder": print inorder traversal
 * 
 * Output:
 * - For "min L R": print the minimum value
 * - For "inorder": print all values in inorder
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CartNode {
    int value;
    int index;
    struct CartNode *left;
    struct CartNode *right;
    struct CartNode *parent;
} CartNode;

typedef struct {
    CartNode *root;
} CartesianTree;

// TODO: Implement createNode(): create a new tree node

// TODO: Implement build(): build Cartesian tree from array using stack
//       Algorithm: process elements left to right, maintain right spine

// TODO: Implement rangeMin(): find minimum value in range using tree structure

// TODO: Implement inorderHelper(): recursive inorder traversal

// TODO: Implement inorder(): wrapper for inorder traversal

// TODO: Implement freeTree(): free all allocated memory

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // TODO: Build Cartesian tree
    
    int q;
    scanf("%d", &q);
    getchar();
    
    for (int i = 0; i < q; i++) {
        char operation[10];
        scanf("%s", operation);
        
        // TODO: Handle operations based on command
    }
    
    free(arr);
    return 0;
}
