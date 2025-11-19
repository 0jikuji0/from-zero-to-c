/**
 * Exercise 29: Articulation Points and Bridges (Cut Vertices)
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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int disc[1005], low[1005], timer = 0;
bool visited[1005];
vector<pair<int, int>> bridges;
vector<int> articulation_points;
vector<int> adj[1005];

void dfs(int u, int parent) {
    visited[u] = true;
    disc[u] = low[u] = timer++;
    int children = 0;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            dfs(v, u);
            
            low[u] = min(low[u], low[v]);
            
            if ((parent == -1 && children > 1) || (parent != -1 && low[v] > disc[u])) {
                if (parent != -1 && low[v] > disc[u]) {
                    bridges.push_back({min(u, v), max(u, v)});
                }
            }
            
            if (parent != -1 && low[v] > disc[u]) {
                articulation_points.push_back(u);
            }
        } else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
    
    if (parent == -1 && children > 1) {
        articulation_points.push_back(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }
    
    sort(articulation_points.begin(), articulation_points.end());
    articulation_points.erase(unique(articulation_points.begin(), articulation_points.end()), articulation_points.end());
    
    sort(bridges.begin(), bridges.end());
    bridges.erase(unique(bridges.begin(), bridges.end()), bridges.end());
    
    cout << "Articulation Points: ";
    for (int v : articulation_points) {
        cout << v << " ";
    }
    cout << endl;
    
    cout << "Bridges: " << endl;
    for (auto& b : bridges) {
        cout << b.first << " - " << b.second << endl;
    }
    
    return 0;
}
