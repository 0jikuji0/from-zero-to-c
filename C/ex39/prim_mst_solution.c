/**
 * Exercise 39: Prim's Algorithm (Minimum Spanning Tree)
 * Difficulty: ***** (5/5)
 * 
 * Implement Prim's algorithm to find the Minimum Spanning Tree (MST) of a weighted graph.
 * Use a priority queue (min-heap) to select edges with minimum weight.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v weight) representing undirected weighted edges
 * 
 * Output:
 * - Print total weight of MST
 * - Print all edges in MST
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Edge {
    int vertex;
    int weight;
    struct Edge* next;
} Edge;

typedef struct {
    int u, v, weight;
} MSTEdge;

void addEdge(Edge** adj, int u, int v, int weight) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->vertex = v;
    newEdge->weight = weight;
    newEdge->next = adj[u];
    adj[u] = newEdge;
}

void prim(int n, Edge** adj) {
    bool* inMST = (bool*)malloc(sizeof(bool) * n);
    int* key = (int*)malloc(sizeof(int) * n);
    int* parent = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        inMST[i] = false;
        parent[i] = -1;
    }
    
    key[0] = 0;
    
    MSTEdge* mst = (MSTEdge*)malloc(sizeof(MSTEdge) * (n - 1));
    int mst_count = 0;
    long long total_weight = 0;
    
    for (int count = 0; count < n; count++) {
        int u = -1;
        int minKey = INF;
        
        for (int v = 0; v < n; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        
        if (u == -1) break;
        
        inMST[u] = true;
        
        if (parent[u] != -1) {
            mst[mst_count].u = parent[u];
            mst[mst_count].v = u;
            mst[mst_count].weight = key[u];
            mst_count++;
            total_weight += key[u];
        }
        
        Edge* edge = adj[u];
        while (edge != NULL) {
            int v = edge->vertex;
            int weight = edge->weight;
            
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
            
            edge = edge->next;
        }
    }
    
    printf("Total MST weight: %lld\n", total_weight);
    printf("MST edges:\n");
    for (int i = 0; i < mst_count; i++) {
        printf("%d - %d: %d\n", mst[i].u, mst[i].v, mst[i].weight);
    }
    
    free(inMST);
    free(key);
    free(parent);
    free(mst);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Edge** adj = (Edge**)malloc(sizeof(Edge*) * n);
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        addEdge(adj, u, v, weight);
        addEdge(adj, v, u, weight);
    }
    
    prim(n, adj);
    
    for (int i = 0; i < n; i++) {
        Edge* edge = adj[i];
        while (edge != NULL) {
            Edge* temp = edge;
            edge = edge->next;
            free(temp);
        }
    }
    free(adj);
    
    return 0;
}
