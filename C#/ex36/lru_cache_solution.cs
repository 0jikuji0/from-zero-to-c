/**
 * Exercise 36: LRU Cache
 * Difficulty: ***** (5/5)
 * 
 * Solution using Dictionary and LinkedList for O(1) get and put operations.
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
    private int capacity;
    private Dictionary<int, LinkedListNode<CacheItem>> cache;
    private LinkedList<CacheItem> lruList;

    public LRUCache(int capacity)
    {
        this.capacity = capacity;
        cache = new Dictionary<int, LinkedListNode<CacheItem>>();
        lruList = new LinkedList<CacheItem>();
    }

    public int Get(int key)
    {
        if (!cache.ContainsKey(key))
        {
            return -1;
        }

        // Move accessed item to front (most recently used)
        LinkedListNode<CacheItem> node = cache[key];
        lruList.Remove(node);
        lruList.AddFirst(node);

        return node.Value.Value;
    }

    public void Put(int key, int value)
    {
        if (cache.ContainsKey(key))
        {
            // Update existing key
            LinkedListNode<CacheItem> node = cache[key];
            node.Value.Value = value;
            
            // Move to front (most recently used)
            lruList.Remove(node);
            lruList.AddFirst(node);
        }
        else
        {
            // Check capacity
            if (cache.Count >= capacity)
            {
                // Remove least recently used (last item)
                LinkedListNode<CacheItem> lru = lruList.Last;
                cache.Remove(lru.Value.Key);
                lruList.RemoveLast();
            }

            // Add new item to front
            CacheItem newItem = new CacheItem(key, value);
            LinkedListNode<CacheItem> newNode = new LinkedListNode<CacheItem>(newItem);
            lruList.AddFirst(newNode);
            cache[key] = newNode;
        }
    }
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

            if (operation == "get")
            {
                int key = int.Parse(input[1]);
                Console.WriteLine(cache.Get(key));
            }
            else if (operation == "put")
            {
                int key = int.Parse(input[1]);
                int value = int.Parse(input[2]);
                cache.Put(key, value);
            }
        }
    }
}
