/**
 * Exercise 47: Skip List
 * Difficulty: ***** (5/5)
 * 
 * Implement a Skip List, a probabilistic data structure that provides
 * O(log n) average time complexity for search, insertion, and deletion.
 * A skip list consists of multiple levels of sorted linked lists.
 * 
 * Operations:
 * - Insert(key, value): Insert a key-value pair with random height
 * - Search(key): Find a value by key
 * - Delete(key): Remove an entry by key
 * - Display(): Print all elements
 * 
 * Skip lists use a coin flip approach to determine node heights,
 * providing balance without complex rotations like AVL or Red-Black trees.
 * 
 * Input:
 * - First line: number of operations N
 * - Next N lines: operation commands
 *   - "insert X Y": insert key X with value Y
 *   - "search X": search for key X
 *   - "delete X": delete key X
 *   - "display": print all elements
 * 
 * Output:
 * - For "search X": print value if found, else "Not found"
 * - For "display": print all key-value pairs in sorted order
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEVEL 16

typedef struct SkipNode {
    int key;
    int value;
    struct SkipNode **forward;
    int level;
} SkipNode;

typedef struct {
    SkipNode *header;
    int level;
} SkipList;

// TODO: Implement randomLevel(): generate random level for new node

// TODO: Implement createNode(): create new skip list node

// TODO: Implement search(): find value by key

// TODO: Implement insert(): insert key-value pair with random level

// TODO: Implement delete(): remove entry by key

// TODO: Implement display(): print all elements

// TODO: Implement initSkipList(): initialize empty skip list

// TODO: Implement freeSkipList(): free all memory

int main() {
    srand(time(NULL));
    
    int n;
    scanf("%d", &n);
    getchar();
    
    // TODO: Initialize skip list
    
    for (int i = 0; i < n; i++) {
        char operation[20];
        scanf("%s", operation);
        
        // TODO: Handle operations based on command
    }
    
    return 0;
}
