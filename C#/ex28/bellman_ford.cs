/**
 * Exercise 28: Bellman-Ford Algorithm (Shortest Path with Negative Weights)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Bellman-Ford algorithm to find shortest paths from a source vertex
 * to all other vertices in a weighted graph, including graphs with negative edge weights.
 * Also detect negative weight cycles.
 * 
 * Input:
 * - First line: number of vertices (n), edges (m), source vertex (s)
 * - Next m lines: edges (u v weight) representing directed weighted edges
 * 
 * Output:
 * - If negative cycle exists: print "Negative cycle detected"
 * - Otherwise: print shortest distance from source to each vertex
 */

using System;
using System.Collections.Generic;

// TODO: Define edge structure

// TODO: Implement Bellman-Ford algorithm

// TODO: Detect negative weight cycles

class Program {
    static void Main() {
        string[] line1 = Console.ReadLine().Split();
        int n = int.Parse(line1[0]);
        int m = int.Parse(line1[1]);
        int source = int.Parse(line1[2]);
        
        // TODO: Read edges
        
        // TODO: Run Bellman-Ford algorithm
        
        // TODO: Print results
    }
}
