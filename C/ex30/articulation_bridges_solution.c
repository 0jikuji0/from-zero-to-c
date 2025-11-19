/**
 * Exercise 30: Articulation Points and Bridges (Cut Vertices)
 * Difficulty: ***** (5/5)
 * 
 * Find articulation points (cut vertices) and bridges in an undirected graph.
 * An articulation point is a vertex whose removal increases the number of connected components.
 * A bridge is an edge whose removal increases the number of connected components.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing undirected edges
 * 
 * Output:
 * - Print all articulation points
 * - Print all bridges
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 1005

int disc[MAXN], low[MAXN], timer_val = 0;
bool visited[MAXN];
int* adj[MAXN];
int adj_size[MAXN];

typedef struct {
    int u, v;
} Edge;

Edge bridges[MAXN * MAXN];
int bridge_count = 0;

int articulation_points[MAXN];
int ap_count = 0;

void dfs(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = timer_val++;
    int children = 0;
    
    for (int i = 0; i < adj_size[u]; i++) {
        int v = adj[u][i];
        
        if (!visited[v]) {
            children++;
            dfs(v, u);
            
            low[u] = (low[u] < low[v]) ? low[u] : low[v];
            
            if (parent != -1 && low[v] > disc[u]) {
                bridges[bridge_count].u = (u < v) ? u : v;
                bridges[bridge_count].v = (u < v) ? v : u;
                bridge_count++;
            }
            
            if (parent != -1 && low[v] > disc[u]) {
                bool found = false;
                for (int j = 0; j < ap_count; j++) {
                    if (articulation_points[j] == u) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    articulation_points[ap_count++] = u;
                }
            }
        } else if (v != parent) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
    
    if (parent == -1 && children > 1) {
        bool found = false;
        for (int j = 0; j < ap_count; j++) {
            if (articulation_points[j] == u) {
                found = true;
                break;
            }
        }
        if (!found) {
            articulation_points[ap_count++] = u;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(sizeof(int) * n);
        adj_size[i] = 0;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adj_size[u]++] = v;
        adj[v][adj_size[v]++] = u;
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    
    printf("Articulation Points: ");
    for (int i = 0; i < ap_count; i++) {
        printf("%d ", articulation_points[i]);
    }
    printf("\n");
    
    printf("Bridges:\n");
    for (int i = 0; i < bridge_count; i++) {
        printf("%d - %d\n", bridges[i].u, bridges[i].v);
    }
    
    for (int i = 0; i < n; i++) {
        free(adj[i]);
    }
    
    return 0;
}
