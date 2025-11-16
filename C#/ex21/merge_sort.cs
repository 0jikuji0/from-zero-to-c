/**
 * Exercise 21: Merge Sort Algorithm
 * Difficulty: *** (3/5)
 * 
 * Implement the merge sort algorithm to sort a list of integers.
 * Merge sort is a divide-and-conquer sorting algorithm with O(n log n) time complexity.
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

// TODO: Implement merge sort algorithm
// Hint: Use divide-and-conquer to recursively sort and merge

// TODO: Implement merge method to combine two sorted subarrays

// TODO: Print the sorted list

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        
        List<int> arr = new List<int>();
        string[] parts = Console.ReadLine().Split();
        for (int i = 0; i < n; i++) {
            arr.Add(int.Parse(parts[i]));
        }
        
        // TODO: Call merge sort method
        
        // TODO: Print sorted list
    }
}
