/**
 * Exercise 22: Hash Table / Hash Map
 * Difficulty: **** (4/5)
 * 
 * Implement a simple hash table with collision resolution using linear probing.
 * Support insert, search, and delete operations.
 * 
 * Input:
 * - Commands: "insert key value", "search key", "delete key", or "exit"
 * 
 * Output:
 * - For search: print the value if found, or "not found"
 */

using System;
using System.Collections.Generic;

// TODO: Implement hash table entry structure (key, value, is_deleted)

// TODO: Implement hash function

// TODO: Implement insert function with linear probing for collision resolution

// TODO: Implement search function

// TODO: Implement delete function (use tombstone marking)

class Program {
    static void Main() {
        // TODO: Initialize hash table
        
        string cmd;
        while ((cmd = Console.ReadLine()) != null && cmd != "exit") {
            string[] parts = cmd.Split();
            
            // TODO: Parse and execute commands
        }
    }
}
