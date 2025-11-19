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

class Program {
    static int n;
    static List<int>[] adj;
    static int[] color;
    
    static bool IsSafe(int vertex, int c) {
        foreach (int neighbor in adj[vertex]) {
            if (color[neighbor] == c) {
                return false;
            }
        }
        return true;
    }
    
    static bool ColorGraphUtil(int vertex, int maxColors) {
        if (vertex == n) {
            return true;
        }
        
        for (int c = 1; c <= maxColors; c++) {
            if (IsSafe(vertex, c)) {
                color[vertex] = c;
                
                if (ColorGraphUtil(vertex + 1, maxColors)) {
                    return true;
                }
                
                color[vertex] = 0;
            }
        }
        
        return false;
    }
    
    static int FindChromaticNumber() {
        for (int numColors = 1; numColors <= n; numColors++) {
            for (int i = 0; i < n; i++) {
                color[i] = 0;
            }
            
            if (ColorGraphUtil(0, numColors)) {
                return numColors;
            }
        }
        
        return n;
    }
    
    static void Main() {
        int m;
        string[] firstLine = Console.ReadLine().Split();
        n = int.Parse(firstLine[0]);
        m = int.Parse(firstLine[1]);
        
        adj = new List<int>[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new List<int>();
        }
        
        color = new int[n];
        
        for (int i = 0; i < m; i++) {
            string[] line = Console.ReadLine().Split();
            int u = int.Parse(line[0]);
            int v = int.Parse(line[1]);
            
            adj[u].Add(v);
            adj[v].Add(u);
        }
        
        int chromaticNum = FindChromaticNumber();
        
        Console.WriteLine($"Chromatic Number: {chromaticNum}");
        Console.Write("Coloring: ");
        for (int i = 0; i < n; i++) {
            Console.Write(color[i]);
            if (i < n - 1) Console.Write(" ");
        }
        Console.WriteLine();
    }
}
