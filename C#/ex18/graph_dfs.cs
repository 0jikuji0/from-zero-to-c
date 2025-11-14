using System;
using System.Collections.Generic;

// TODO: Define the Graph class with adjacency list
// Hint: Use List<List<int>> for the adjacency list

// TODO: Implement the DFS (Depth-First Search) method
// The method should traverse the graph and print visited nodes

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        
        // TODO: Initialize the graph with n nodes
        
        int m = int.Parse(Console.ReadLine());
        
        for (int i = 0; i < m; i++) {
            string[] parts = Console.ReadLine().Split();
            int u = int.Parse(parts[0]);
            int v = int.Parse(parts[1]);
            // TODO: Add edge from u to v
        }
        
        int start = int.Parse(Console.ReadLine());
        
        // TODO: Perform DFS starting from 'start' node
        
        Console.WriteLine();
    }
}
