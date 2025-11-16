/**
 * Exercise 24: Topological Sort (DAG)
 * Difficulty: ***** (5/5)
 * 
 * Implement topological sorting for a directed acyclic graph (DAG).
 * Use Kahn's algorithm or DFS-based approach.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v)
 * - Last line: starting source
 * 
 * Output:
 * - Print topological order (space-separated)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_EDGES 1000

// TODO: Implement topological sort using DFS or Kahn's algorithm

// TODO: Build adjacency list from input edges

// TODO: Calculate in-degree for each vertex (for Kahn's algorithm)

// TODO: Process and output topological ordering

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // TODO: Initialize graph structures
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // TODO: Add edge to graph
    }
    
    // TODO: Perform topological sort and print result
    
    return 0;
}
