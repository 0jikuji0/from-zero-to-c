/**
 * Exercise 23: Topological Sort (DAG)
 * Difficulty: ***** (5/5)
 * 
 * Implement topological sorting for a directed acyclic graph (DAG).
 * Use Kahn's algorithm for in-degree based ordering.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v)
 * 
 * Output:
 * - Print topological order (space-separated)
 */

using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static void Main() {
        string[] firstLine = Console.ReadLine().Split();
        int n = int.Parse(firstLine[0]);
        int m = int.Parse(firstLine[1]);
        
        List<int>[] adj = new List<int>[n];
        int[] inDegree = new int[n];
        
        for (int i = 0; i < n; i++) {
            adj[i] = new List<int>();
            inDegree[i] = 0;
        }
        
        for (int i = 0; i < m; i++) {
            string[] parts = Console.ReadLine().Split();
            int u = int.Parse(parts[0]);
            int v = int.Parse(parts[1]);
            
            adj[u].Add(v);
            inDegree[v]++;
        }
        
        Queue<int> queue = new Queue<int>();
        
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                queue.Enqueue(i);
            }
        }
        
        List<int> result = new List<int>();
        
        while (queue.Count > 0) {
            int u = queue.Dequeue();
            result.Add(u);
            
            foreach (int v in adj[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue.Enqueue(v);
                }
            }
        }
        
        for (int i = 0; i < result.Count; i++) {
            Console.Write(result[i]);
            if (i < result.Count - 1) Console.Write(" ");
        }
        Console.WriteLine();
    }
}
