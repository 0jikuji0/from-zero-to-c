/**
 * Exercise 23: Hash Table / Hash Map
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

// TODO: Define a hash table entry structure (key, value, is_deleted)

// TODO: Implement hash function

// TODO: Implement insert function with linear probing for collision resolution

// TODO: Implement search function

// TODO: Implement delete function (use tombstone marking)

int main() {
    // TODO: Initialize hash table
    
    char cmd[50];
    while (scanf("%s", cmd) == 1) {
        if (strcmp(cmd, "exit") == 0) {
            break;
        }
        
        // TODO: Parse and execute commands
    }
    
    // TODO: Clean up and free memory
    
    return 0;
}
