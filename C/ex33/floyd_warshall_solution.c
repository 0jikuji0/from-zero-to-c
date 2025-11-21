/**
 * Exercise 33: Floyd-Warshall Algorithm (All-Pairs Shortest Path)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Floyd-Warshall algorithm to find shortest paths between all pairs
 * of vertices in a weighted graph. Handle negative edges and detect negative cycles.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v weight) representing directed weighted edges
 * 
 * Output:
 * - If negative cycle exists: print "Negative cycle detected"
 * - Otherwise: print distance matrix (n x n)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define INF 1000000000

bool floydWarshall(int n, long long dist[][n]) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    long long (*dist)[n] = malloc(sizeof(long long[n][n]));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        long long weight;
        scanf("%d %d %lld", &u, &v, &weight);
        dist[u][v] = weight;
    }
    
    if (!floydWarshall(n, dist)) {
        printf("Negative cycle detected\n");
    } else {
        printf("Shortest distances between all pairs:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] == INF) {
                    printf("INF ");
                } else {
                    printf("%lld ", dist[i][j]);
                }
            }
            printf("\n");
        }
    }
    
    free(dist);
    
    return 0;
}
