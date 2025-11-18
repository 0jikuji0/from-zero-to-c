/**
 * Exercise 28: Maximum Flow (Ford-Fulkerson Algorithm)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Ford-Fulkerson algorithm using DFS
 * to find the maximum flow in a flow network from source to sink.
 * 
 * Input:
 * - First line: number of vertices (n), edges (m), source (s), sink (t)
 * - Next m lines: edges (u v capacity) representing directed edges
 * 
 * Output:
 * - Print the maximum flow from source to sink
 * - Print the residual graph flow for verification
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAXN 105
#define INF 1e18

long long capacity[MAXN][MAXN];
long long flow[MAXN][MAXN];
bool visited[MAXN];
int n, source, sink;

bool dfs(int u, int t, long long f) {
    if (u == t) {
        return true;
    }
    
    visited[u] = true;
    
    for (int v = 0; v < n; v++) {
        if (!visited[v] && capacity[u][v] > flow[u][v]) {
            long long pushFlow = (f < capacity[u][v] - flow[u][v]) ? f : capacity[u][v] - flow[u][v];
            
            if (dfs(v, t, pushFlow)) {
                flow[u][v] += pushFlow;
                flow[v][u] -= pushFlow;
                return true;
            }
        }
    }
    
    return false;
}

long long maxFlow() {
    memset(flow, 0, sizeof(flow));
    
    long long totalFlow = 0;
    
    while (true) {
        memset(visited, false, sizeof(visited));
        
        if (!dfs(source, sink, INF)) {
            break;
        }
        
        for (int v = 0; v < n; v++) {
            if (flow[source][v] > 0) {
                totalFlow += flow[source][v];
            }
        }
    }
    
    totalFlow = 0;
    for (int v = 0; v < n; v++) {
        if (flow[source][v] > 0) {
            totalFlow += flow[source][v];
        }
    }
    
    return totalFlow;
}

int main() {
    int m;
    scanf("%d %d %d %d", &n, &m, &source, &sink);
    
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        long long cap;
        scanf("%d %d %lld", &u, &v, &cap);
        
        capacity[u][v] += cap;
    }
    
    long long result = maxFlow();
    
    printf("Maximum Flow: %lld\n", result);
    
    printf("Flow Details:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (flow[i][j] > 0) {
                printf("%d -> %d: %lld\n", i, j, flow[i][j]);
            }
        }
    }
    
    return 0;
}
