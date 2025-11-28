/**
 * Exercise 35: Binary Heap (Priority Queue)
 * Difficulty: ***** (5/5)
 * 
 * Solution using List<int> to implement a min-heap with standard heap operations.
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

    // Helper method to get parent index
    private int Parent(int index)
    {
        return (index - 1) / 2;
    }

    // Helper method to get left child index
    private int LeftChild(int index)
    {
        return 2 * index + 1;
    }

    // Helper method to get right child index
    private int RightChild(int index)
    {
        return 2 * index + 2;
    }

    // Swap elements at two indices
    private void Swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    // Bubble up element to maintain heap property
    private void HeapifyUp(int index)
    {
        while (index > 0 && heap[Parent(index)] > heap[index])
        {
            Swap(index, Parent(index));
            index = Parent(index);
        }
    }

    // Bubble down element to maintain heap property
    private void HeapifyDown(int index)
    {
        int minIndex = index;
        int left = LeftChild(index);
        int right = RightChild(index);

        if (left < heap.Count && heap[left] < heap[minIndex])
        {
            minIndex = left;
        }

        if (right < heap.Count && heap[right] < heap[minIndex])
        {
            minIndex = right;
        }

        if (index != minIndex)
        {
            Swap(index, minIndex);
            HeapifyDown(minIndex);
        }
    }

    // Insert element into heap
    public void Insert(int value)
    {
        heap.Add(value);
        HeapifyUp(heap.Count - 1);
    }

    // Extract minimum element
    public int? ExtractMin()
    {
        if (heap.Count == 0)
        {
            return null;
        }

        int min = heap[0];
        heap[0] = heap[heap.Count - 1];
        heap.RemoveAt(heap.Count - 1);

        if (heap.Count > 0)
        {
            HeapifyDown(0);
        }

        return min;
    }

    // Peek at minimum element without removing
    public int? Peek()
    {
        if (heap.Count == 0)
        {
            return null;
        }
        return heap[0];
    }

    // Check if heap is empty
    public bool IsEmpty()
    {
        return heap.Count == 0;
    }
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

            if (operation == "insert")
            {
                int value = int.Parse(input[1]);
                heap.Insert(value);
            }
            else if (operation == "extract")
            {
                int? min = heap.ExtractMin();
                if (min.HasValue)
                {
                    Console.WriteLine(min.Value);
                }
                else
                {
                    Console.WriteLine("Heap is empty");
                }
            }
            else if (operation == "peek")
            {
                int? min = heap.Peek();
                if (min.HasValue)
                {
                    Console.WriteLine(min.Value);
                }
                else
                {
                    Console.WriteLine("Heap is empty");
                }
            }
            else if (operation == "empty")
            {
                Console.WriteLine(heap.IsEmpty().ToString().ToLower());
            }
        }
    }
}
