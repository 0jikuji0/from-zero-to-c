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

class HashEntry {
    public string Key { get; set; }
    public int Value { get; set; }
    public bool IsDeleted { get; set; }
    
    public HashEntry(string key, int value) {
        Key = key;
        Value = value;
        IsDeleted = false;
    }
}

class HashTable {
    private const int TABLE_SIZE = 100;
    private HashEntry[] entries;
    
    public HashTable() {
        entries = new HashEntry[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++) {
            entries[i] = null;
        }
    }
    
    private int HashFunction(string key) {
        int hash = 0;
        foreach (char c in key) {
            hash = (hash << 5) + hash + c;
        }
        return Math.Abs(hash) % TABLE_SIZE;
    }
    
    public void Insert(string key, int value) {
        int index = HashFunction(key);
        
        while (entries[index] != null && !entries[index].IsDeleted) {
            if (entries[index].Key == key) {
                entries[index].Value = value;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
        
        entries[index] = new HashEntry(key, value);
    }
    
    public int Search(string key) {
        int index = HashFunction(key);
        int iterations = 0;
        
        while (entries[index] != null && iterations < TABLE_SIZE) {
            if (!entries[index].IsDeleted && entries[index].Key == key) {
                return entries[index].Value;
            }
            index = (index + 1) % TABLE_SIZE;
            iterations++;
        }
        
        return -1;
    }
    
    public void Delete(string key) {
        int index = HashFunction(key);
        int iterations = 0;
        
        while (entries[index] != null && iterations < TABLE_SIZE) {
            if (!entries[index].IsDeleted && entries[index].Key == key) {
                entries[index].IsDeleted = true;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            iterations++;
        }
    }
}

class Program {
    static void Main() {
        HashTable table = new HashTable();
        
        string cmd;
        while ((cmd = Console.ReadLine()) != null && cmd != "exit") {
            string[] parts = cmd.Split();
            
            if (parts[0] == "insert" && parts.Length == 3) {
                string key = parts[1];
                int value = int.Parse(parts[2]);
                table.Insert(key, value);
            } else if (parts[0] == "search" && parts.Length == 2) {
                string key = parts[1];
                int result = table.Search(key);
                if (result != -1) {
                    Console.WriteLine(result);
                } else {
                    Console.WriteLine("not found");
                }
            } else if (parts[0] == "delete" && parts.Length == 2) {
                string key = parts[1];
                table.Delete(key);
            }
        }
    }
}
