/**
 * Exercise 26: Graph Coloring (Chromatic Number)
 * Difficulty: ***** (5/5)
 * 
 * Implement graph coloring using backtracking to find the chromatic number.
 * The chromatic number is the minimum number of colors needed to color a graph
 * such that no two adjacent vertices have the same color.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing connections
 * 
 * Output:
 * - Print the chromatic number
 * - Print a valid coloring assignment for each vertex
 */

using System;
using System.Collections.Generic;

// TODO: Define graph structure with adjacency list

// TODO: Implement isSafe function to check if a color can be assigned

// TODO: Implement colorGraphUtil backtracking function

// TODO: Implement chromatic number finding algorithm

class Program {
    static void Main() {
        int n, m;
        string[] firstLine = Console.ReadLine().Split();
        n = int.Parse(firstLine[0]);
        m = int.Parse(firstLine[1]);
        
        // TODO: Read graph edges
        
        // TODO: Find chromatic number and coloring
        
        // TODO: Print results
    }
}
