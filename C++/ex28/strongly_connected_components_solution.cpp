/**
 * Exercise 28: Strongly Connected Components (Kosaraju Algorithm)
 * Difficulty: ***** (5/5)
 * 
 * Find all strongly connected components in a directed graph using Kosaraju algorithm.
 * A strongly connected component is a maximal set of vertices where every vertex
 * is reachable from every other vertex.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing directed edges
 * 
 * Output:
 * - Print the number of strongly connected components
 * - Print vertices in each component
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs1(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v, adj, visited, st);
        }
    }
    
    st.push(u);
}

void dfs2(int u, vector<vector<int>>& adj_transpose, vector<bool>& visited, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    
    for (int v : adj_transpose[u]) {
        if (!visited[v]) {
            dfs2(v, adj_transpose, visited, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n), adj_transpose(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj_transpose[v].push_back(u);
    }
    
    vector<bool> visited(n, false);
    stack<int> st;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs1(i, adj, visited, st);
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    
    vector<vector<int>> sccs;
    
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, adj_transpose, visited, component);
            sccs.push_back(component);
        }
    }
    
    cout << "Number of SCCs: " << sccs.size() << endl;
    
    for (int i = 0; i < sccs.size(); i++) {
        cout << "SCC " << (i + 1) << ": ";
        for (int v : sccs[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    
    return 0;
}
