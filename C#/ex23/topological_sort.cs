/**
 * Exercise 23: Topological Sort (DAG)
 * Difficulty: ***** (5/5)
 * 
 * Implement topological sorting for a directed acyclic graph (DAG).
 * Use Kahn's algorithm for in-degree based ordering.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v)
 * 
 * Output:
 * - Print topological order (space-separated)
 */

using System;
using System.Collections.Generic;
using System.Linq;

// TODO: Implement topological sort using Kahn's algorithm

// TODO: Build adjacency list from input edges

// TODO: Calculate in-degree for each vertex

// TODO: Process and output topological ordering

class Program {
    static void Main() {
        string[] firstLine = Console.ReadLine().Split();
        int n = int.Parse(firstLine[0]);
        int m = int.Parse(firstLine[1]);
        
        // TODO: Initialize graph structures
        
        for (int i = 0; i < m; i++) {
            string[] parts = Console.ReadLine().Split();
            int u = int.Parse(parts[0]);
            int v = int.Parse(parts[1]);
            // TODO: Add edge to graph
        }
        
        // TODO: Perform topological sort and print result
    }
}
