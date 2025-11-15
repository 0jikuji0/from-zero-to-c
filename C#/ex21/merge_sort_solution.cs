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

class Program {
    static void Merge(List<int> arr, int left, int mid, int right) {
        List<int> leftArr = new List<int>();
        List<int> rightArr = new List<int>();
        
        for (int i = left; i <= mid; i++) {
            leftArr.Add(arr[i]);
        }
        for (int i = mid + 1; i <= right; i++) {
            rightArr.Add(arr[i]);
        }
        
        int i1 = 0, i2 = 0, k = left;
        
        while (i1 < leftArr.Count && i2 < rightArr.Count) {
            if (leftArr[i1] <= rightArr[i2]) {
                arr[k++] = leftArr[i1++];
            } else {
                arr[k++] = rightArr[i2++];
            }
        }
        
        while (i1 < leftArr.Count) {
            arr[k++] = leftArr[i1++];
        }
        
        while (i2 < rightArr.Count) {
            arr[k++] = rightArr[i2++];
        }
    }
    
    static void MergeSort(List<int> arr, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            
            MergeSort(arr, left, mid);
            MergeSort(arr, mid + 1, right);
            Merge(arr, left, mid, right);
        }
    }
    
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        
        List<int> arr = new List<int>();
        string[] parts = Console.ReadLine().Split();
        for (int i = 0; i < n; i++) {
            arr.Add(int.Parse(parts[i]));
        }
        
        MergeSort(arr, 0, n - 1);
        
        for (int i = 0; i < n; i++) {
            Console.Write(arr[i]);
            if (i < n - 1) Console.Write(" ");
        }
        Console.WriteLine();
    }
}
