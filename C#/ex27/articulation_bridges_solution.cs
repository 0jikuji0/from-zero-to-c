/**
 * Exercise 27: Articulation Points and Bridges (Cut Vertices)
 * Difficulty: ***** (5/5)
 * 
 * Find articulation points (cut vertices) and bridges in an undirected graph.
 * An articulation point is a vertex whose removal increases the number of connected components.
 * A bridge is an edge whose removal increases the number of connected components.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing undirected edges
 * 
 * Output:
 * - Print all articulation points
 * - Print all bridges
 */

using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static int[] disc, low;
    static int timer = 0;
    static bool[] visited;
    static List<(int, int)> bridges;
    static List<int> articulation_points;
    static List<int>[] adj;
    
    static void DFS(int u, int parent) {
        visited[u] = true;
        disc[u] = low[u] = timer++;
        int children = 0;
        
        foreach (int v in adj[u]) {
            if (!visited[v]) {
                children++;
                DFS(v, u);
                
                low[u] = Math.Min(low[u], low[v]);
                
                if (parent != -1 && low[v] > disc[u]) {
                    bridges.Add((Math.Min(u, v), Math.Max(u, v)));
                }
                
                if (parent != -1 && low[v] > disc[u]) {
                    articulation_points.Add(u);
                }
            } else if (v != parent) {
                low[u] = Math.Min(low[u], disc[v]);
            }
        }
        
        if (parent == -1 && children > 1) {
            articulation_points.Add(u);
        }
    }
    
    static void Main() {
        string[] line1 = Console.ReadLine().Split();
        int n = int.Parse(line1[0]);
        int m = int.Parse(line1[1]);
        
        adj = new List<int>[n];
        disc = new int[n];
        low = new int[n];
        visited = new bool[n];
        bridges = new List<(int, int)>();
        articulation_points = new List<int>();
        
        for (int i = 0; i < n; i++) {
            adj[i] = new List<int>();
        }
        
        for (int i = 0; i < m; i++) {
            string[] edge = Console.ReadLine().Split();
            int u = int.Parse(edge[0]);
            int v = int.Parse(edge[1]);
            adj[u].Add(v);
            adj[v].Add(u);
        }
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, -1);
            }
        }
        
        articulation_points = articulation_points.Distinct().ToList();
        articulation_points.Sort();
        
        bridges = bridges.Distinct().ToList();
        bridges.Sort();
        
        Console.Write("Articulation Points: ");
        foreach (int v in articulation_points) {
            Console.Write(v + " ");
        }
        Console.WriteLine();
        
        Console.WriteLine("Bridges:");
        foreach (var b in bridges) {
            Console.WriteLine(b.Item1 + " - " + b.Item2);
        }
    }
}
