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

class Program {
    const long INF = 1000000000;
    
    static bool FloydWarshall(int n, long[,] dist) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i, k] != INF && dist[k, j] != INF) {
                        if (dist[i, k] + dist[k, j] < dist[i, j]) {
                            dist[i, j] = dist[i, k] + dist[k, j];
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (dist[i, i] < 0) {
                return false;
            }
        }
        
        return true;
    }
    
    static void Main() {
        string[] line1 = Console.ReadLine().Split();
        int n = int.Parse(line1[0]);
        int m = int.Parse(line1[1]);
        
        long[,] dist = new long[n, n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dist[i, j] = 0;
                } else {
                    dist[i, j] = INF;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            string[] edgeLine = Console.ReadLine().Split();
            int u = int.Parse(edgeLine[0]);
            int v = int.Parse(edgeLine[1]);
            long weight = long.Parse(edgeLine[2]);
            dist[u, v] = weight;
        }
        
        if (!FloydWarshall(n, dist)) {
            Console.WriteLine("Negative cycle detected");
        } else {
            Console.WriteLine("Shortest distances between all pairs:");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i, j] == INF) {
                        Console.Write("INF ");
                    } else {
                        Console.Write(dist[i, j] + " ");
                    }
                }
                Console.WriteLine();
            }
        }
    }
}
