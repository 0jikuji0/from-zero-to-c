/**
 * Exercise 29: Trie (Prefix Tree)
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

using System;
using System.Collections.Generic;

class TrieNode {
    public Dictionary<char, TrieNode> Children { get; set; }
    public bool IsEndOfWord { get; set; }
    
    public TrieNode() {
        Children = new Dictionary<char, TrieNode>();
        IsEndOfWord = false;
    }
}

class Trie {
    private TrieNode root;
    
    public Trie() {
        root = new TrieNode();
    }
    
    public void Insert(string word) {
        TrieNode current = root;
        
        foreach (char c in word) {
            if (!current.Children.ContainsKey(c)) {
                current.Children[c] = new TrieNode();
            }
            current = current.Children[c];
        }
        
        current.IsEndOfWord = true;
    }
    
    public bool Search(string word) {
        TrieNode current = root;
        
        foreach (char c in word) {
            if (!current.Children.ContainsKey(c)) {
                return false;
            }
            current = current.Children[c];
        }
        
        return current.IsEndOfWord;
    }
    
    public bool StartsWith(string prefix) {
        TrieNode current = root;
        
        foreach (char c in prefix) {
            if (!current.Children.ContainsKey(c)) {
                return false;
            }
            current = current.Children[c];
        }
        
        return true;
    }
}

class Program {
    static void Main() {
        int q = int.Parse(Console.ReadLine());
        
        Trie trie = new Trie();
        
        for (int i = 0; i < q; i++) {
            string[] parts = Console.ReadLine().Split();
            string operation = parts[0];
            string word = parts[1];
            
            if (operation == "insert") {
                trie.Insert(word);
            } else if (operation == "search") {
                Console.WriteLine(trie.Search(word) ? "true" : "false");
            } else if (operation == "prefix") {
                Console.WriteLine(trie.StartsWith(word) ? "true" : "false");
            }
        }
    }
}
