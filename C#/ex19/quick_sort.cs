using System;
using System.Collections.Generic;

// TODO: Implement the quicksort algorithm
// Hint: Use a partition method to divide the list

// TODO: Implement the partition method that places a pivot
// in its correct sorted position and returns the pivot index

// TODO: Print the array in sorted order (space-separated)

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        
        List<int> arr = new List<int>();
        string[] parts = Console.ReadLine().Split();
        for (int i = 0; i < n; i++) {
            arr.Add(int.Parse(parts[i]));
        }
        
        // TODO: Call quicksort method
        
        // TODO: Print sorted list
    }
}
