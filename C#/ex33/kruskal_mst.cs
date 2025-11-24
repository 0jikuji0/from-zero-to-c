/**
 * Exercise 33: Kruskal's Algorithm (Minimum Spanning Tree)
 * Difficulty: ***** (5/5)
 * 
 * Implement Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a weighted graph.
 * Use Disjoint Set Union (Union-Find) to detect cycles.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v weight) representing undirected weighted edges
 * 
 * Output:
 * - Print total weight of MST
 * - Print all edges in MST
 */

using System;
using System.Collections.Generic;
using System.Linq;

// TODO: Define edge class

// TODO: Implement DSU (Union-Find) with path compression

// TODO: Implement Kruskal's algorithm

class Program {
    static void Main() {
        string[] line1 = Console.ReadLine().Split();
        int n = int.Parse(line1[0]);
        int m = int.Parse(line1[1]);
        
        // TODO: Read edges
        
        // TODO: Run Kruskal's algorithm
        
        // TODO: Print results
    }
}
