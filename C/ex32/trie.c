/**
 * Exercise 32: Trie (Prefix Tree)
 * Difficulty: ***** (5/5)
 * 
 * Implement a Trie data structure for efficient string storage and retrieval.
 * Support insertion, search, and prefix matching operations.
 * 
 * Input:
 * - First line: number of operations (q)
 * - Next q lines: operations in format:
 *   - "insert word" - insert word into trie
 *   - "search word" - check if word exists
 *   - "prefix word" - check if any word starts with prefix
 * 
 * Output:
 * - For each search/prefix operation: print "true" or "false"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

// TODO: Define trie node structure

// TODO: Implement trie creation

// TODO: Implement insert operation

// TODO: Implement search operation

// TODO: Implement prefix search operation

int main() {
    int q;
    scanf("%d", &q);
    
    // TODO: Create trie
    
    for (int i = 0; i < q; i++) {
        char operation[10], word[100];
        scanf("%s %s", operation, word);
        
        // TODO: Process operations
    }
    
    return 0;
}
