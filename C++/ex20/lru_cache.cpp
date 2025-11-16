/**
 * Exercise 20: LRU (Least Recently Used) Cache
 * Difficulty: ***** (5/5)
 * 
 * Implement an LRU Cache that supports get and put operations.
 * When the cache reaches capacity, evict the least recently used item.
 * 
 * Input:
 * - First line: cache capacity
 * - Second line: number of operations
 * - Next n lines: operations ("get key" or "put key value")
 * 
 * Output:
 * - For each get operation, print the value (or -1 if not found)
 */

#include <bits/stdc++.h>
using namespace std;

// TODO: Implement a hash table structure or use unordered_map

// TODO: Implement LRU Cache class with get and put operations
// Hint: Use a combination of unordered_map and doubly linked list

class LRUCache {
private:
    // TODO: Define data members for capacity and cache storage
    
public:
    LRUCache(int capacity) {
        // TODO: Initialize the cache with given capacity
    }
    
    // TODO: Implement get method that returns cached value or -1
    int get(int key) {
        
    }
    
    // TODO: Implement put method that stores or updates a key-value pair
    void put(int key, int value) {
        
    }
};

int main() {
    int capacity;
    cin >> capacity;
    
    LRUCache cache(capacity);
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        string cmd;
        cin >> cmd;
        
        if (cmd == "get") {
            int key;
            cin >> key;
            cout << cache.get(key) << "\n";
        } else if (cmd == "put") {
            int key, value;
            cin >> key >> value;
            cache.put(key, value);
        }
    }
    
    return 0;
}
