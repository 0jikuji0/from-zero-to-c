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

// TODO: Define trie node structure

// TODO: Implement trie creation

// TODO: Implement insert operation

// TODO: Implement search operation

// TODO: Implement prefix search operation

class Program {
    static void Main() {
        int q = int.Parse(Console.ReadLine());
        
        // TODO: Create trie
        
        for (int i = 0; i < q; i++) {
            string[] parts = Console.ReadLine().Split();
            string operation = parts[0];
            string word = parts[1];
            
            // TODO: Process operations
        }
    }
}
