/**
 * Exercise 36: Disjoint Set Union (Union-Find)
 * Difficulty: ***** (5/5)
 * 
 * Implement a Disjoint Set Union (DSU) data structure with path compression
 * and union by rank optimizations. Support find and union operations.
 * 
 * Input:
 * - First line: number of elements (n) and number of operations (q)
 * - Next q lines: operations in format:
 *   - "union u v" - union sets containing u and v
 *   - "find u v" - check if u and v are in same set
 * 
 * Output:
 * - For each find operation: print "yes" or "no"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool connected(int x, int y) {
    return find(x) == find(y);
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    makeSet(n);
    
    for (int i = 0; i < q; i++) {
        char operation[10];
        scanf("%s", operation);
        
        if (strcmp(operation, "union") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            unionSets(u, v);
        } else if (strcmp(operation, "find") == 0) {
            int u, v;
            scanf("%d %d", &u, &v);
            printf("%s\n", connected(u, v) ? "yes" : "no");
        }
    }
    
    free(parent);
    free(rank_arr);
    
    return 0;
}
