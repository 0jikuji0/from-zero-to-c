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

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
} TrieNode;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = false;
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    
    return node;
}

void insert(TrieNode* root, const char* word) {
    TrieNode* current = root;
    
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        
        current = current->children[index];
    }
    
    current->isEndOfWord = true;
}

bool search(TrieNode* root, const char* word) {
    TrieNode* current = root;
    
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        
        if (current->children[index] == NULL) {
            return false;
        }
        
        current = current->children[index];
    }
    
    return current != NULL && current->isEndOfWord;
}

bool startsWith(TrieNode* root, const char* prefix) {
    TrieNode* current = root;
    
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = prefix[i] - 'a';
        
        if (current->children[index] == NULL) {
            return false;
        }
        
        current = current->children[index];
    }
    
    return true;
}

int main() {
    int q;
    scanf("%d", &q);
    
    TrieNode* root = createNode();
    
    for (int i = 0; i < q; i++) {
        char operation[10], word[100];
        scanf("%s %s", operation, word);
        
        if (strcmp(operation, "insert") == 0) {
            insert(root, word);
        } else if (strcmp(operation, "search") == 0) {
            printf("%s\n", search(root, word) ? "true" : "false");
        } else if (strcmp(operation, "prefix") == 0) {
            printf("%s\n", startsWith(root, word) ? "true" : "false");
        }
    }
    
    return 0;
}
