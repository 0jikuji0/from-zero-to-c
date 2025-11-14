/**
 * Exercise 19: Quicksort Algorithm
 * Difficulty: *** (3/5)
 * 
 * Implement the quicksort algorithm to sort a list of integers.
 * Quicksort uses a divide-and-conquer approach with a pivot element.
 * 
 * Input:
 * - First line: number of elements (n)
 * - Second line: n integers to be sorted (space-separated)
 * 
 * Output:
 * - Print the sorted list in ascending order (space-separated)
 */

using System;
using System.Collections.Generic;

class Program {
    static int Partition(List<int> arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        int temp2 = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp2;
        return i + 1;
    }
    
    static void QuickSort(List<int> arr, int low, int high) {
        if (low < high) {
            int pi = Partition(arr, low, high);
            
            QuickSort(arr, low, pi - 1);
            QuickSort(arr, pi + 1, high);
        }
    }
    
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        
        List<int> arr = new List<int>();
        string[] parts = Console.ReadLine().Split();
        for (int i = 0; i < n; i++) {
            arr.Add(int.Parse(parts[i]));
        }
        
        QuickSort(arr, 0, n - 1);
        
        for (int i = 0; i < n; i++) {
            Console.Write(arr[i]);
            if (i < n - 1) Console.Write(" ");
        }
        Console.WriteLine();
    }
}
