/**
 * Exercise 38: Binary Min-Heap
 * Difficulty: ***** (5/5)
 * 
 * Implement a Min-Heap data structure using a List<int>.
 * A heap is a complete binary tree where each parent node has a value less
 * than or equal to its children (heap property).
 * 
 * Operations:
 * - Insert: Add element and bubble up to maintain heap property
 * - ExtractMin: Remove and return minimum (root), then bubble down
 * - Peek: Return minimum without removing
 * - IsEmpty: Check if heap is empty
 * 
 * Use array indexing for parent-child relationships:
 * - Parent of i: (i-1)/2
 * - Left child of i: 2*i + 1
 * - Right child of i: 2*i + 2
 * 
 * Input:
 * - First line: number of operations N
 * - Next N lines: operation commands
 *   - "insert X": insert value X
 *   - "extract": extract and print minimum
 *   - "peek": print minimum without removing
 *   - "empty": print "true" or "false"
 * 
 * Output:
 * - For "extract": print minimum value (or "Heap is empty")
 * - For "peek": print minimum value (or "Heap is empty")
 * - For "empty": print "true" or "false"
 */

using System;
using System.Collections.Generic;

class MinHeap
{
    private List<int> heap;

    public MinHeap()
    {
        heap = new List<int>();
    }

    // TODO: Implement Parent(index): return parent index

    // TODO: Implement LeftChild(index): return left child index

    // TODO: Implement RightChild(index): return right child index

    // TODO: Implement Swap(i, j): swap elements at indices i and j

    // TODO: Implement HeapifyUp(index): bubble up to maintain heap property

    // TODO: Implement HeapifyDown(index): bubble down to maintain heap property

    // TODO: Implement Insert(value): add element and heapify up

    // TODO: Implement ExtractMin(): remove root, replace with last, heapify down

    // TODO: Implement Peek(): return root without removing

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
