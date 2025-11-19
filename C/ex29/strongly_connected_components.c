/**
 * Exercise 29: Strongly Connected Components (Kosaraju Algorithm)
 * Difficulty: ***** (5/5)
 * 
 * Find all strongly connected components in a directed graph using Kosaraju algorithm.
 * A strongly connected component is a maximal set of vertices where every vertex
 * is reachable from every other vertex.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing directed edges
 * 
 * Output:
 * - Print the number of strongly connected components
 * - Print vertices in each component
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// TODO: Define graph structure with adjacency lists

// TODO: Implement DFS for first traversal to fill stack

// TODO: Implement DFS for second traversal on transpose graph

// TODO: Implement Kosaraju algorithm

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // TODO: Build adjacency list for original graph
    
    // TODO: Find SCCs using Kosaraju algorithm
    
    // TODO: Print results
    
    return 0;
}
