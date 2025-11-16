/**
 * Exercise 16: Graph Depth-First Search (DFS)
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

#include <bits/stdc++.h>
using namespace std;

// TODO: Define a graph structure using adjacency list
// Hint: Use vector<vector<int>> for the adjacency list

// TODO: Implement the DFS (Depth-First Search) function
// The function should traverse the graph and print visited nodes

int main() {
    int n;
    cin >> n;
    
    // TODO: Initialize the graph with n nodes
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // TODO: Add edge from u to v
    }
    
    int start;
    cin >> start;
    
    // TODO: Perform DFS starting from 'start' node
    
    cout << "\n";
    
    return 0;
}
