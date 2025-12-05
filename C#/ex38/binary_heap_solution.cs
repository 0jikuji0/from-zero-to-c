/**
 * Exercise 38: Binary Min-Heap
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing a Min-Heap using List<int>.
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

    private int Parent(int index)
    {
        return (index - 1) / 2;
    }

    private int LeftChild(int index)
    {
        return 2 * index + 1;
    }

    private int RightChild(int index)
    {
        return 2 * index + 2;
    }

    private void Swap(int i, int j)
    {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }

    private void HeapifyUp(int index)
    {
        while (index > 0 && heap[Parent(index)] > heap[index])
        {
            Swap(index, Parent(index));
            index = Parent(index);
        }
    }

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

    public void Insert(int value)
    {
        heap.Add(value);
        HeapifyUp(heap.Count - 1);
    }

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

    public int? Peek()
    {
        if (heap.Count == 0)
        {
            return null;
        }
        return heap[0];
    }

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
                int? result = heap.ExtractMin();
                if (result.HasValue)
                {
                    Console.WriteLine(result.Value);
                }
                else
                {
                    Console.WriteLine("Heap is empty");
                }
            }
            else if (operation == "peek")
            {
                int? result = heap.Peek();
                if (result.HasValue)
                {
                    Console.WriteLine(result.Value);
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
