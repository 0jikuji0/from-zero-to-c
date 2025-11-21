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

class Edge {
    public int U { get; set; }
    public int V { get; set; }
    public int Weight { get; set; }
    
    public Edge(int u, int v, int weight) {
        U = u;
        V = v;
        Weight = weight;
    }
}

class Program {
    static bool BellmanFord(int n, List<Edge> edges, int source, long[] dist) {
        const long INF = long.MaxValue;
        
        for (int i = 0; i < n; i++) {
            dist[i] = INF;
        }
        dist[source] = 0;
        
        for (int i = 0; i < n - 1; i++) {
            foreach (var edge in edges) {
                if (dist[edge.U] != INF && dist[edge.U] + edge.Weight < dist[edge.V]) {
                    dist[edge.V] = dist[edge.U] + edge.Weight;
                }
            }
        }
        
        foreach (var edge in edges) {
            if (dist[edge.U] != INF && dist[edge.U] + edge.Weight < dist[edge.V]) {
                return false;
            }
        }
        
        return true;
    }
    
    static void Main() {
        string[] line1 = Console.ReadLine().Split();
        int n = int.Parse(line1[0]);
        int m = int.Parse(line1[1]);
        int source = int.Parse(line1[2]);
        
        List<Edge> edges = new List<Edge>();
        
        for (int i = 0; i < m; i++) {
            string[] edgeLine = Console.ReadLine().Split();
            int u = int.Parse(edgeLine[0]);
            int v = int.Parse(edgeLine[1]);
            int weight = int.Parse(edgeLine[2]);
            edges.Add(new Edge(u, v, weight));
        }
        
        long[] dist = new long[n];
        
        if (!BellmanFord(n, edges, source, dist)) {
            Console.WriteLine("Negative cycle detected");
        } else {
            Console.WriteLine($"Shortest distances from vertex {source}:");
            for (int i = 0; i < n; i++) {
                if (dist[i] == long.MaxValue) {
                    Console.WriteLine($"Vertex {i}: INF");
                } else {
                    Console.WriteLine($"Vertex {i}: {dist[i]}");
                }
            }
        }
    }
}
