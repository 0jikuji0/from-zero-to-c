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

class Edge : IComparable<Edge> {
    public int U { get; set; }
    public int V { get; set; }
    public int Weight { get; set; }
    
    public Edge(int u, int v, int weight) {
        U = u;
        V = v;
        Weight = weight;
    }
    
    public int CompareTo(Edge other) {
        return Weight.CompareTo(other.Weight);
    }
}

class DSU {
    private int[] parent;
    private int[] rank;
    
    public DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    public int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }
    
    public void Union(int x, int y) {
        int xRoot = Find(x);
        int yRoot = Find(y);
        
        if (xRoot == yRoot) {
            return;
        }
        
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
}

class Program {
    static void Kruskal(int n, List<Edge> edges) {
        edges.Sort();
        
        DSU dsu = new DSU(n);
        
        List<Edge> mst = new List<Edge>();
        long total_weight = 0;
        
        foreach (var edge in edges) {
            if (dsu.Find(edge.U) != dsu.Find(edge.V)) {
                mst.Add(edge);
                total_weight += edge.Weight;
                dsu.Union(edge.U, edge.V);
                
                if (mst.Count == n - 1) {
                    break;
                }
            }
        }
        
        Console.WriteLine($"Total MST weight: {total_weight}");
        Console.WriteLine("MST edges:");
        foreach (var edge in mst) {
            Console.WriteLine($"{edge.U} - {edge.V}: {edge.Weight}");
        }
    }
    
    static void Main() {
        string[] line1 = Console.ReadLine().Split();
        int n = int.Parse(line1[0]);
        int m = int.Parse(line1[1]);
        
        List<Edge> edges = new List<Edge>();
        
        for (int i = 0; i < m; i++) {
            string[] edgeLine = Console.ReadLine().Split();
            int u = int.Parse(edgeLine[0]);
            int v = int.Parse(edgeLine[1]);
            int weight = int.Parse(edgeLine[2]);
            edges.Add(new Edge(u, v, weight));
        }
        
        Kruskal(n, edges);
    }
}
