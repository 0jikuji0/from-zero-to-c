/**
 * Exercise 26: Strongly Connected Components (Kosaraju Algorithm)
 * Difficulty: ***** (5/5)
 * 
 * Find all strongly connected components in a directed graph using Kosaraju algorithm.
 * A strongly connected component is a maximal set of vertices where every vertex
 * is reachable from every other vertex.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing directed edges
 * 
 * Output:
 * - Print the number of strongly connected components
 * - Print vertices in each component
 */

using System;
using System.Collections.Generic;

// TODO: Define graph structure with adjacency lists

// TODO: Implement DFS for first traversal to fill stack

// TODO: Implement DFS for second traversal on transpose graph

// TODO: Implement Kosaraju algorithm

class Program {
    static void Main() {
        int n, m;
        string[] line1 = Console.ReadLine().Split();
        n = int.Parse(line1[0]);
        m = int.Parse(line1[1]);
        
        // TODO: Build adjacency list for original graph
        
        // TODO: Find SCCs using Kosaraju algorithm
        
        // TODO: Print results
    }
}
