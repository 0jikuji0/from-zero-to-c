/**
 * Exercise 21: Dijkstra's Shortest Path Algorithm
 * Difficulty: ***** (5/5)
 * 
 * Implement Dijkstra's algorithm to find shortest paths from a source node
 * to all other nodes in a weighted graph.
 * 
 * Input:
 * - First line: number of nodes (n) and edges (m)
 * - Next m lines: edges (u v w) with weight w
 * - Last line: source node
 * 
 * Output:
 * - Print shortest distances from source to all nodes (space-separated)
 * - Use INT_MAX or a large value for unreachable nodes
 */

#include <bits/stdc++.h>
using namespace std;

// TODO: Implement Dijkstra's shortest path algorithm
// Hint: Use a priority queue (min-heap) for efficient node selection

// TODO: Build the graph from input

// TODO: Print shortest distances from source to all nodes

int main() {
    int n, m;
    cin >> n >> m;
    
    // TODO: Initialize adjacency list
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // TODO: Add edge to graph
    }
    
    int source;
    cin >> source;
    
    // TODO: Run Dijkstra's algorithm
    
    // TODO: Print distances
    
    return 0;
}
