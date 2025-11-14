#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

// TODO: Define an adjacency list structure for the graph
// Hint: You need a structure to store edges for each node

// TODO: Implement the DFS (Depth-First Search) function
// The function should traverse the graph and print visited nodes

// TODO: Implement the addEdge function to add an edge to the graph

int main() {
    int n; // number of nodes
    scanf("%d", &n);
    
    // TODO: Initialize the graph
    
    int m; // number of edges
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        // TODO: Add edge from u to v
    }
    
    int start;
    scanf("%d", &start);
    
    // TODO: Perform DFS starting from 'start' node
    
    printf("\n");
    
    return 0;
}
