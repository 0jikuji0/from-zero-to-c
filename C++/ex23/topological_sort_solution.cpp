/**
 * Exercise 23: Topological Sort (DAG)
 * Difficulty: ***** (5/5)
 * 
 * Implement topological sorting for a directed acyclic graph (DAG).
 * Use Kahn's algorithm for in-degree based ordering.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v)
 * 
 * Output:
 * - Print topological order (space-separated)
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n);
    vector<int> inDegree(n, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        inDegree[v]++;
    }
    
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> result;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}
