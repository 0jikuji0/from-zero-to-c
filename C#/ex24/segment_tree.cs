/**
 * Exercise 24: Segment Tree (Range Sum Query)
 * Difficulty: ***** (5/5)
 * 
 * Implement a segment tree to support range sum queries and point updates.
 * 
 * Input:
 * - First line: number of elements (n)
 * - Second line: array of n integers
 * - Third line: number of operations
 * - Next lines: operations ("query l r" or "update idx val")
 * 
 * Output:
 * - For each query: print the sum of elements from index l to r
 */

using System;
using System.Collections.Generic;

// TODO: Define segment tree structure

// TODO: Implement build function to construct the segment tree

// TODO: Implement query function for range sum queries

// TODO: Implement update function for point updates

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        
        string[] arrStr = Console.ReadLine().Split();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = int.Parse(arrStr[i]);
        }
        
        // TODO: Build segment tree
        
        int m = int.Parse(Console.ReadLine());
        
        for (int i = 0; i < m; i++) {
            string[] parts = Console.ReadLine().Split();
            
            if (parts[0][0] == 'q') {  // query
                int l = int.Parse(parts[1]);
                int r = int.Parse(parts[2]);
                // TODO: Execute query
            } else {  // update
                int idx = int.Parse(parts[1]);
                int val = int.Parse(parts[2]);
                // TODO: Execute update
            }
        }
    }
}
