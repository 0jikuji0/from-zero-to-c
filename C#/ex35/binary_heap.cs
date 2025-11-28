/**
 * Exercise 35: Binary Heap (Priority Queue)
 * Difficulty: ***** (5/5)
 * 
 * Implement a Min-Heap data structure with the following operations:
 * - Insert(value): Add an element to the heap
 * - ExtractMin(): Remove and return the minimum element
 * - Peek(): Return the minimum element without removing it
 * - IsEmpty(): Check if the heap is empty
 * 
 * A binary heap is a complete binary tree that satisfies the heap property:
 * for a min-heap, each parent node has a value less than or equal to its children.
 * It's commonly used to implement priority queues.
 * 
 * Use a List<int> to represent the heap array. Implement the standard
 * heap operations with O(log n) insert and extract.
 * 
 * Input:
 * - First line: number of operations N
 * - Next N lines: operation commands
 *   - "insert X": insert value X
 *   - "extract": extract and print minimum value
 *   - "peek": print minimum value without removing
 *   - "empty": print "true" or "false"
 * 
 * Output:
 * - For "extract", "peek", "empty": print the result
 * - For "extract" on empty heap: print "Heap is empty"
 * - For "peek" on empty heap: print "Heap is empty"
 */

using System;
using System.Collections.Generic;

class MinHeap
{
    // TODO: Use List<int> to store heap elements
    
    // TODO: Implement helper methods:
    //       - Parent(index): return parent index
    //       - LeftChild(index): return left child index
    //       - RightChild(index): return right child index
    //       - Swap(i, j): swap elements at indices i and j
    
    // TODO: Implement HeapifyUp(index): bubble up element to maintain heap property
    
    // TODO: Implement HeapifyDown(index): bubble down element to maintain heap property
    
    // TODO: Implement Insert(value): add element and heapify up
    
    // TODO: Implement ExtractMin(): remove root, replace with last element, heapify down
    
    // TODO: Implement Peek(): return root element without removing
    
    // TODO: Implement IsEmpty(): check if heap is empty
}

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        MinHeap heap = new MinHeap();
        
        for (int i = 0; i < n; i++)
        {
            string[] input = Console.ReadLine().Split();
            string operation = input[0];
            
            // TODO: Handle operations based on command
        }
    }
}
