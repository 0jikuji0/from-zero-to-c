// Max Subarray (Exercise 11) - Solution
// Find the maximum sum of a contiguous subarray using Kadane's algorithm.

using System;
using System.Collections.Generic;

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine()!);
        
        string? line = Console.ReadLine();
        if (line == null) return;
        
        var parts = line.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
        List<int> arr = new List<int>();
        foreach (string part in parts) {
            if (int.TryParse(part, out int val)) {
                arr.Add(val);
            }
        }
        
        long maxSum = arr[0];
        long currentSum = arr[0];
        
        for (int i = 1; i < arr.Count; i++) {
            currentSum = Math.Max(arr[i], currentSum + arr[i]);
            maxSum = Math.Max(maxSum, currentSum);
        }
        
        Console.WriteLine(maxSum);
    }
}
