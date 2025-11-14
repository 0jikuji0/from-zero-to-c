/**
 * Exercise 18: Graph Depth-First Search (DFS)
 * Difficulty: **** (4/5)
 * 
 * Implement a graph representation using an adjacency list and perform
 * a depth-first search traversal starting from a given node.
 * 
 * Input:
 * - First line: number of nodes (n)
 * - Second line: number of edges (m)
 * - Next m lines: edges (u v) representing an edge from u to v
 * - Last line: starting node for DFS
 * 
 * Output:
 * - Print all visited nodes in DFS order, space-separated, ending with newline
 */

using System;
using System.Collections.Generic;

class Graph {
    private int numNodes;
    private List<List<int>> adj;
    
    public Graph(int n) {
        numNodes = n;
        adj = new List<List<int>>();
        for (int i = 0; i < n; i++) {
            adj.Add(new List<int>());
        }
    }
    
    public void AddEdge(int u, int v) {
        adj[u].Add(v);
    }
    
    private void DfsHelper(int node, bool[] visited) {
        visited[node] = true;
        Console.Write(node + " ");
        
        foreach (int neighbor in adj[node]) {
            if (!visited[neighbor]) {
                DfsHelper(neighbor, visited);
            }
        }
    }
    
    public void Dfs(int start) {
        bool[] visited = new bool[numNodes];
        DfsHelper(start, visited);
    }
}

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        
        Graph graph = new Graph(n);
        
        int m = int.Parse(Console.ReadLine());
        
        for (int i = 0; i < m; i++) {
            string[] parts = Console.ReadLine().Split();
            int u = int.Parse(parts[0]);
            int v = int.Parse(parts[1]);
            graph.AddEdge(u, v);
        }
        
        int start = int.Parse(Console.ReadLine());
        
        graph.Dfs(start);
        
        Console.WriteLine();
    }
}
