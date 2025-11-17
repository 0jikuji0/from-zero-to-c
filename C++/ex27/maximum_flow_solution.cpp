/**
 * Exercise 27: Maximum Flow (Ford-Fulkerson Algorithm)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Ford-Fulkerson algorithm using DFS (Edmonds-Karp style)
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 105;
const long long INF = 1e18;

int n, source, sink;
long long capacity[MAXN][MAXN];
long long flow[MAXN][MAXN];
vector<int> adj[MAXN];

bool dfs(int u, int t, long long f, vector<bool>& visited) {
    if (u == t) {
        return true;
    }
    
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v] && capacity[u][v] > flow[u][v]) {
            long long pushFlow = min(f, capacity[u][v] - flow[u][v]);
            
            if (dfs(v, t, pushFlow, visited)) {
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
        vector<bool> visited(n, false);
        
        if (!dfs(source, sink, INF, visited)) {
            break;
        }
        
        long long pathFlow = INF;
        for (int u = source; u != sink; ) {
            for (int v : adj[u]) {
                if (flow[u][v] > 0 && capacity[u][v] - flow[u][v] >= 0) {
                    pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
                    break;
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (i != source) {
            for (int j : adj[source]) {
                if (i == j) {
                    totalFlow += flow[source][i];
                    break;
                }
            }
        }
    }
    
    totalFlow = 0;
    for (int v : adj[source]) {
        totalFlow += flow[source][v];
    }
    
    return totalFlow;
}

int main() {
    int m;
    cin >> n >> m >> source >> sink;
    
    memset(capacity, 0, sizeof(capacity));
    
    for (int i = 0; i < m; i++) {
        int u, v;
        long long cap;
        cin >> u >> v >> cap;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
        capacity[u][v] += cap;
    }
    
    long long result = maxFlow();
    
    cout << "Maximum Flow: " << result << endl;
    
    cout << "Flow Details:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j : adj[i]) {
            if (flow[i][j] > 0) {
                cout << i << " -> " << j << ": " << flow[i][j] << endl;
            }
        }
    }
    
    return 0;
}
