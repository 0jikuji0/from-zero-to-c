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
