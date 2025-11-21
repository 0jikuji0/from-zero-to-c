/**
 * Exercise 31: Bellman-Ford Algorithm (Shortest Path with Negative Weights)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Bellman-Ford algorithm to find shortest paths from a source vertex
 * to all other vertices in a weighted graph, including graphs with negative edge weights.
 * Also detect negative weight cycles.
 * 
 * Input:
 * - First line: number of vertices (n), edges (m), source vertex (s)
 * - Next m lines: edges (u v weight) representing directed weighted edges
 * 
 * Output:
 * - If negative cycle exists: print "Negative cycle detected"
 * - Otherwise: print shortest distance from source to each vertex
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int u, v, weight;
} Edge;

bool bellmanFord(int n, Edge* edges, int m, int source, long long* dist) {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[source] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, m, source;
    scanf("%d %d %d", &n, &m, &source);
    
    Edge* edges = (Edge*)malloc(sizeof(Edge) * m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
    long long* dist = (long long*)malloc(sizeof(long long) * n);
    
    if (!bellmanFord(n, edges, m, source, dist)) {
        printf("Negative cycle detected\n");
    } else {
        printf("Shortest distances from vertex %d:\n", source);
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) {
                printf("Vertex %d: INF\n", i);
            } else {
                printf("Vertex %d: %lld\n", i, dist[i]);
            }
        }
    }
    
    free(edges);
    free(dist);
    
    return 0;
}
