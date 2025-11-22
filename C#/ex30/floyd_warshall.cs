/**
 * Exercise 30: Floyd-Warshall Algorithm (All-Pairs Shortest Path)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Floyd-Warshall algorithm to find shortest paths between all pairs
 * of vertices in a weighted graph. Handle negative edges and detect negative cycles.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v weight) representing directed weighted edges
 * 
 * Output:
 * - If negative cycle exists: print "Negative cycle detected"
 * - Otherwise: print distance matrix (n x n)
 */

using System;
using System.Collections.Generic;

// TODO: Initialize distance matrix

// TODO: Implement Floyd-Warshall algorithm

// TODO: Detect negative cycles

class Program {
    static void Main() {
        string[] line1 = Console.ReadLine().Split();
        int n = int.Parse(line1[0]);
        int m = int.Parse(line1[1]);
        
        // TODO: Read edges and build distance matrix
        
        // TODO: Run Floyd-Warshall algorithm
        
        // TODO: Print results
    }
}
