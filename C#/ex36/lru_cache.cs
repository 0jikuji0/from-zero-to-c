/**
 * Exercise 36: LRU Cache
 * Difficulty: ***** (5/5)
 * 
 * Implement a Least Recently Used (LRU) Cache with the following operations:
 * - Get(key): Get the value of the key if it exists, otherwise return -1
 * - Put(key, value): Insert or update the key-value pair
 * 
 * When the cache reaches its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * Both operations should run in O(1) time complexity.
 * 
 * Use a combination of:
 * - Dictionary<int, LinkedListNode<CacheItem>> for O(1) access
 * - LinkedList<CacheItem> to maintain LRU order
 * 
 * The most recently used item is at the front, least recently used at the back.
 * 
 * Input:
 * - First line: capacity of the cache (positive integer)
 * - Second line: number of operations N
 * - Next N lines: operation commands
 *   - "get X": get value for key X
 *   - "put X Y": put key X with value Y
 * 
 * Output:
 * - For "get X": print the value or -1 if not found
 * - For "put": no output (unless debugging)
 * 
 * Example:
 * Input:
 * 2
 * 5
 * put 1 10
 * put 2 20
 * get 1
 * put 3 30
 * get 2
 * 
 * Output:
 * 10
 * -1
 * 
 * Explanation: After putting 3, key 2 was evicted (LRU), so get(2) returns -1
 */

using System;
using System.Collections.Generic;

class CacheItem
{
    public int Key { get; set; }
    public int Value { get; set; }

    public CacheItem(int key, int value)
    {
        Key = key;
        Value = value;
    }
}

class LRUCache
{
    // TODO: Declare Dictionary<int, LinkedListNode<CacheItem>> for fast lookup
    
    // TODO: Declare LinkedList<CacheItem> to maintain order (front = most recent)
    
    // TODO: Declare capacity field
    
    // TODO: Constructor to initialize capacity and data structures
    
    // TODO: Implement Get(key):
    //       - If key exists, move node to front and return value
    //       - Otherwise return -1
    
    // TODO: Implement Put(key, value):
    //       - If key exists, update value and move to front
    //       - If key doesn't exist:
    //         - If at capacity, remove least recently used (back of list)
    //         - Add new item to front
    
    // TODO: Helper method MoveToFront(node): remove and add to front
}

class Program
{
    static void Main()
    {
        int capacity = int.Parse(Console.ReadLine());
        int n = int.Parse(Console.ReadLine());
        LRUCache cache = new LRUCache(capacity);

        for (int i = 0; i < n; i++)
        {
            string[] input = Console.ReadLine().Split();
            string operation = input[0];

            // TODO: Handle "get" and "put" operations
        }
    }
}
