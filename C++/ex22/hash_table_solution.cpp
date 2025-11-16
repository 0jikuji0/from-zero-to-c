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

#include <bits/stdc++.h>
using namespace std;

const int TABLE_SIZE = 100;

struct HashEntry {
    string key;
    int value;
    bool is_deleted;
    
    HashEntry() : key(""), value(0), is_deleted(true) {}
    HashEntry(const string& k, int v) : key(k), value(v), is_deleted(false) {}
};

class HashTable {
private:
    vector<HashEntry> entries;
    
    unsigned int hashFunction(const string& key) {
        unsigned int hash = 0;
        for (char c : key) {
            hash = (hash << 5) + hash + c;
        }
        return hash % TABLE_SIZE;
    }
    
public:
    HashTable() : entries(TABLE_SIZE) {}
    
    void insert(const string& key, int value) {
        unsigned int index = hashFunction(key);
        
        while (!entries[index].is_deleted && entries[index].key != key) {
            index = (index + 1) % TABLE_SIZE;
        }
        
        entries[index] = HashEntry(key, value);
    }
    
    int search(const string& key) {
        unsigned int index = hashFunction(key);
        int iterations = 0;
        
        while (iterations < TABLE_SIZE) {
            if (!entries[index].is_deleted && entries[index].key == key) {
                return entries[index].value;
            }
            index = (index + 1) % TABLE_SIZE;
            iterations++;
        }
        
        return -1;
    }
    
    void deleteKey(const string& key) {
        unsigned int index = hashFunction(key);
        int iterations = 0;
        
        while (iterations < TABLE_SIZE) {
            if (!entries[index].is_deleted && entries[index].key == key) {
                entries[index].is_deleted = true;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            iterations++;
        }
    }
};

int main() {
    HashTable table;
    
    string cmd;
    while (cin >> cmd && cmd != "exit") {
        if (cmd == "insert") {
            string key;
            int value;
            cin >> key >> value;
            table.insert(key, value);
        } else if (cmd == "search") {
            string key;
            cin >> key;
            int result = table.search(key);
            if (result != -1) {
                cout << result << "\n";
            } else {
                cout << "not found\n";
            }
        } else if (cmd == "delete") {
            string key;
            cin >> key;
            table.deleteKey(key);
        }
    }
    
    return 0;
}
