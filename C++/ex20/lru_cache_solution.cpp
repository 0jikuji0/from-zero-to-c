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

class LRUCache {
private:
    int capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> lruList;
    
public:
    LRUCache(int cap) : capacity(cap) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        // Move to front (most recently used)
        lruList.erase(cache[key].second);
        lruList.push_front(key);
        cache[key].second = lruList.begin();
        
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update value and move to front
            lruList.erase(cache[key].second);
            lruList.push_front(key);
            cache[key] = {value, lruList.begin()};
        } else {
            // New key
            if (cache.size() == capacity) {
                // Evict least recently used
                int lru = lruList.back();
                lruList.pop_back();
                cache.erase(lru);
            }
            
            lruList.push_front(key);
            cache[key] = {value, lruList.begin()};
        }
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
