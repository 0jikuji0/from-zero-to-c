/**
 * Exercise 46: Disjoint Set Union (Union-Find)
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing DSU with union by rank and path compression.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *parent;
    int *rank;
    int n;
} DSU;

DSU* createDSU(int n) {
    DSU *dsu = (DSU*)malloc(sizeof(DSU));
    dsu->n = n;
    dsu->parent = (int*)malloc(n * sizeof(int));
    dsu->rank = (int*)calloc(n, sizeof(int));
    
    // Initialize: each element is its own parent
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = i;
    }
    
    return dsu;
}

int find(DSU *dsu, int x) {
    if (dsu->parent[x] != x) {
        // Path compression: make parent point directly to root
        dsu->parent[x] = find(dsu, dsu->parent[x]);
    }
    return dsu->parent[x];
}

void unionSets(DSU *dsu, int x, int y) {
    int rootX = find(dsu, x);
    int rootY = find(dsu, y);
    
    if (rootX == rootY) {
        return; // Already in same set
    }
    
    // Union by rank: attach smaller tree under larger tree
    if (dsu->rank[rootX] < dsu->rank[rootY]) {
        dsu->parent[rootX] = rootY;
    } else if (dsu->rank[rootX] > dsu->rank[rootY]) {
        dsu->parent[rootY] = rootX;
    } else {
        dsu->parent[rootY] = rootX;
        dsu->rank[rootX]++;
    }
}

int connected(DSU *dsu, int x, int y) {
    return find(dsu, x) == find(dsu, y);
}

void freeDSU(DSU *dsu) {
    free(dsu->parent);
    free(dsu->rank);
    free(dsu);
}

int main() {
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    getchar();
    
    DSU *dsu = createDSU(n);
    
    for (int i = 0; i < q; i++) {
        char operation[20];
        scanf("%s", operation);
        
        if (strcmp(operation, "union") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            unionSets(dsu, x, y);
        } else if (strcmp(operation, "find") == 0) {
            int x;
            scanf("%d", &x);
            printf("%d\n", find(dsu, x));
        } else if (strcmp(operation, "connected") == 0) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%s\n", connected(dsu, x, y) ? "true" : "false");
        }
    }
    
    freeDSU(dsu);
    return 0;
}
