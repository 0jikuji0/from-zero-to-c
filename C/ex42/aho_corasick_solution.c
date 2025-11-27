/**
 * Exercise 42: Aho-Corasick Algorithm (Multi-Pattern Matching)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Aho-Corasick algorithm for finding multiple patterns
 * in a text simultaneously. This algorithm builds a finite state machine
 * (trie + failure links) to achieve O(n + m + z) complexity where:
 * - n = total length of all patterns
 * - m = text length
 * - z = number of pattern occurrences
 * 
 * Applications:
 * - Antivirus scanning
 * - Intrusion detection systems
 * - DNA sequence matching
 * - Text editors (find multiple keywords)
 * 
 * Input:
 * - First line: number of patterns k
 * - Next k lines: patterns to search for
 * - Last line: text to search in
 * 
 * Output:
 * - For each pattern found, print: "Pattern 'X' found at position Y"
 * - If no patterns found, print: "No patterns found"
 * - Output sorted by position, then by pattern index
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 26
#define MAX_PATTERNS 100
#define MAX_LEN 1005
#define MAX_NODES 10005

typedef struct TrieNode {
    struct TrieNode* children[MAX_CHARS];
    struct TrieNode* failure;
    int output[MAX_PATTERNS];
    int outputCount;
} TrieNode;

typedef struct {
    int patternIdx;
    int position;
} Match;

TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < MAX_CHARS; i++) {
        node->children[i] = NULL;
    }
    node->failure = NULL;
    node->outputCount = 0;
    return node;
}

void insertPattern(TrieNode* root, const char* pattern, int patternIdx) {
    TrieNode* current = root;
    int len = strlen(pattern);
    
    for (int i = 0; i < len; i++) {
        int idx = pattern[i] - 'a';
        if (current->children[idx] == NULL) {
            current->children[idx] = createNode();
        }
        current = current->children[idx];
    }
    
    current->output[current->outputCount++] = patternIdx;
}

void buildFailureLinks(TrieNode* root) {
    TrieNode* queue[MAX_NODES];
    int front = 0, rear = 0;
    
    for (int i = 0; i < MAX_CHARS; i++) {
        if (root->children[i] != NULL) {
            root->children[i]->failure = root;
            queue[rear++] = root->children[i];
        }
    }
    
    while (front < rear) {
        TrieNode* current = queue[front++];
        
        for (int i = 0; i < MAX_CHARS; i++) {
            if (current->children[i] != NULL) {
                TrieNode* child = current->children[i];
                queue[rear++] = child;
                
                TrieNode* failure = current->failure;
                while (failure != root && failure->children[i] == NULL) {
                    failure = failure->failure;
                }
                
                if (failure->children[i] != NULL && failure->children[i] != child) {
                    child->failure = failure->children[i];
                } else {
                    child->failure = root;
                }
                
                for (int j = 0; j < child->failure->outputCount; j++) {
                    child->output[child->outputCount++] = child->failure->output[j];
                }
            }
        }
    }
}

int compareMatches(const void* a, const void* b) {
    Match* m1 = (Match*)a;
    Match* m2 = (Match*)b;
    if (m1->position != m2->position) {
        return m1->position - m2->position;
    }
    return m1->patternIdx - m2->patternIdx;
}

void search(TrieNode* root, const char* text, char patterns[][MAX_LEN], int k) {
    Match matches[MAX_NODES];
    int matchCount = 0;
    
    TrieNode* current = root;
    int len = strlen(text);
    
    for (int i = 0; i < len; i++) {
        int idx = text[i] - 'a';
        
        while (current != root && current->children[idx] == NULL) {
            current = current->failure;
        }
        
        if (current->children[idx] != NULL) {
            current = current->children[idx];
        }
        
        if (current->outputCount > 0) {
            for (int j = 0; j < current->outputCount; j++) {
                int patternIdx = current->output[j];
                int patternLen = strlen(patterns[patternIdx]);
                int position = i - patternLen + 1;
                
                matches[matchCount].patternIdx = patternIdx;
                matches[matchCount].position = position;
                matchCount++;
            }
        }
    }
    
    if (matchCount == 0) {
        printf("No patterns found\n");
    } else {
        qsort(matches, matchCount, sizeof(Match), compareMatches);
        
        for (int i = 0; i < matchCount; i++) {
            printf("Pattern '%s' found at position %d\n", 
                   patterns[matches[i].patternIdx], 
                   matches[i].position);
        }
    }
}

void freeTrie(TrieNode* node) {
    if (node == NULL) return;
    
    for (int i = 0; i < MAX_CHARS; i++) {
        if (node->children[i] != NULL) {
            freeTrie(node->children[i]);
        }
    }
    free(node);
}

int main() {
    int k;
    scanf("%d", &k);
    getchar();
    
    char patterns[MAX_PATTERNS][MAX_LEN];
    TrieNode* root = createNode();
    
    for (int i = 0; i < k; i++) {
        fgets(patterns[i], MAX_LEN, stdin);
        patterns[i][strcspn(patterns[i], "\n")] = 0;
        insertPattern(root, patterns[i], i);
    }
    
    buildFailureLinks(root);
    
    char text[MAX_LEN * 10];
    fgets(text, MAX_LEN * 10, stdin);
    text[strcspn(text, "\n")] = 0;
    
    search(root, text, patterns, k);
    
    freeTrie(root);
    
    return 0;
}
