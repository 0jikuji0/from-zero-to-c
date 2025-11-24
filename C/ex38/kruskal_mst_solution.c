/**
 * Exercise 38: Kruskal's Algorithm (Minimum Spanning Tree)
 * Difficulty: ***** (5/5)
 * 
 * Implement Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a weighted graph.
 * Use Disjoint Set Union (Union-Find) to detect cycles.
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

typedef struct {
    int u, v, weight;
} Edge;

int* parent;
int* rank_arr;

void makeSet(int n) {
    parent = (int*)malloc(sizeof(int) * n);
    rank_arr = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank_arr[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int xRoot = find(x);
    int yRoot = find(y);
    
    if (xRoot == yRoot) {
        return;
    }
    
    if (rank_arr[xRoot] < rank_arr[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank_arr[xRoot] > rank_arr[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank_arr[xRoot]++;
    }
}

int compareEdges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}

void kruskal(int n, Edge* edges, int m) {
    qsort(edges, m, sizeof(Edge), compareEdges);
    
    makeSet(n);
    
    Edge* mst = (Edge*)malloc(sizeof(Edge) * (n - 1));
    int mst_count = 0;
    long long total_weight = 0;
    
    for (int i = 0; i < m && mst_count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        
        if (find(u) != find(v)) {
            mst[mst_count++] = edges[i];
            total_weight += edges[i].weight;
            unionSets(u, v);
        }
    }
    
    printf("Total MST weight: %lld\n", total_weight);
    printf("MST edges:\n");
    for (int i = 0; i < mst_count; i++) {
        printf("%d - %d: %d\n", mst[i].u, mst[i].v, mst[i].weight);
    }
    
    free(mst);
    free(parent);
    free(rank_arr);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    Edge* edges = (Edge*)malloc(sizeof(Edge) * m);
    
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
    kruskal(n, edges, m);
    
    free(edges);
    
    return 0;
}
