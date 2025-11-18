/**
 * Exercise 27: Graph Coloring (Chromatic Number)
 * Difficulty: ***** (5/5)
 * 
 * Implement graph coloring using backtracking to find the chromatic number.
 * The chromatic number is the minimum number of colors needed to color a graph
 * such that no two adjacent vertices have the same color.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing connections
 * 
 * Output:
 * - Print the chromatic number
 * - Print a valid coloring assignment for each vertex
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int* vertices;
    int size;
} Adjacency;

int n;
Adjacency* adj;
int* color;

bool isSafe(int vertex, int c) {
    for (int i = 0; i < adj[vertex].size; i++) {
        int neighbor = adj[vertex].vertices[i];
        if (color[neighbor] == c) {
            return false;
        }
    }
    return true;
}

bool colorGraphUtil(int vertex, int maxColors) {
    if (vertex == n) {
        return true;
    }
    
    for (int c = 1; c <= maxColors; c++) {
        if (isSafe(vertex, c)) {
            color[vertex] = c;
            
            if (colorGraphUtil(vertex + 1, maxColors)) {
                return true;
            }
            
            color[vertex] = 0;
        }
    }
    
    return false;
}

int findChromaticNumber() {
    for (int numColors = 1; numColors <= n; numColors++) {
        memset(color, 0, sizeof(int) * n);
        
        if (colorGraphUtil(0, numColors)) {
            return numColors;
        }
    }
    
    return n;
}

int main() {
    int m;
    scanf("%d %d", &n, &m);
    
    adj = (Adjacency*)malloc(sizeof(Adjacency) * n);
    for (int i = 0; i < n; i++) {
        adj[i].vertices = (int*)malloc(sizeof(int) * n);
        adj[i].size = 0;
    }
    
    color = (int*)malloc(sizeof(int) * n);
    memset(color, 0, sizeof(int) * n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        adj[u].vertices[adj[u].size++] = v;
        adj[v].vertices[adj[v].size++] = u;
    }
    
    int chromaticNum = findChromaticNumber();
    
    printf("Chromatic Number: %d\n", chromaticNum);
    printf("Coloring: ");
    for (int i = 0; i < n; i++) {
        printf("%d", color[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    for (int i = 0; i < n; i++) {
        free(adj[i].vertices);
    }
    free(adj);
    free(color);
    
    return 0;
}
