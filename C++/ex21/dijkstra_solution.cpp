/**
 * Exercise 21: Dijkstra's Shortest Path Algorithm
 * Difficulty: ***** (5/5)
 * 
 * Implement Dijkstra's algorithm to find shortest paths from a source node
 * to all other nodes in a weighted graph.
 * 
 * Input:
 * - First line: number of nodes (n) and edges (m)
 * - Next m lines: edges (u v w) with weight w
 * - Last line: source node
 * 
 * Output:
 * - Print shortest distances from source to all nodes (space-separated)
 * - Use INT_MAX or a large value for unreachable nodes
 */

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, int>>> adj(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int source;
    cin >> source;
    
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << dist[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
