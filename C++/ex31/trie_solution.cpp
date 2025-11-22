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

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    
    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(const string& word) {
        TrieNode* current = root;
        
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        
        current->isEndOfWord = true;
    }
    
    bool search(const string& word) {
        TrieNode* current = root;
        
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        
        return current->isEndOfWord;
    }
    
    bool startsWith(const string& prefix) {
        TrieNode* current = root;
        
        for (char c : prefix) {
            if (current->children.find(c) == current->children.end()) {
                return false;
            }
            current = current->children[c];
        }
        
        return true;
    }
};

int main() {
    int q;
    cin >> q;
    
    Trie trie;
    
    for (int i = 0; i < q; i++) {
        string operation, word;
        cin >> operation >> word;
        
        if (operation == "insert") {
            trie.insert(word);
        } else if (operation == "search") {
            cout << (trie.search(word) ? "true" : "false") << endl;
        } else if (operation == "prefix") {
            cout << (trie.startsWith(word) ? "true" : "false") << endl;
        }
    }
    
    return 0;
}
