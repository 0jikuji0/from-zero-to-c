/**
 * Exercise 19: Graph Depth-First Search (DFS)
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct {
    int* nodes;
    int count;
    int capacity;
} AdjList;

typedef struct {
    AdjList adj[MAX_NODES];
    int numNodes;
} Graph;

void initGraph(Graph* graph, int n) {
    graph->numNodes = n;
    for (int i = 0; i < n; i++) {
        graph->adj[i].nodes = malloc(sizeof(int) * 10);
        graph->adj[i].capacity = 10;
        graph->adj[i].count = 0;
    }
}

void addEdge(Graph* graph, int u, int v) {
    if (graph->adj[u].count == graph->adj[u].capacity) {
        graph->adj[u].capacity *= 2;
        graph->adj[u].nodes = realloc(graph->adj[u].nodes, 
                                       sizeof(int) * graph->adj[u].capacity);
    }
    graph->adj[u].nodes[graph->adj[u].count++] = v;
}

void dfs(Graph* graph, int node, int* visited) {
    visited[node] = 1;
    printf("%d ", node);
    
    for (int i = 0; i < graph->adj[node].count; i++) {
        int neighbor = graph->adj[node].nodes[i];
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numNodes; i++) {
        free(graph->adj[i].nodes);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    Graph graph;
    initGraph(&graph, n);
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }
    
    int start;
    scanf("%d", &start);
    
    int visited[MAX_NODES] = {0};
    dfs(&graph, start, visited);
    
    printf("\n");
    
    freeGraph(&graph);
    
    return 0;
}
