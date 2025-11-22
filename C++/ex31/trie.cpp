/**
 * Exercise 31: Trie (Prefix Tree)
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

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// TODO: Define trie node structure

// TODO: Implement trie class

// TODO: Implement insert operation

// TODO: Implement search operation

// TODO: Implement prefix search operation

int main() {
    int q;
    cin >> q;
    
    // TODO: Create trie
    
    for (int i = 0; i < q; i++) {
        string operation, word;
        cin >> operation >> word;
        
        // TODO: Process operations
    }
    
    return 0;
}
