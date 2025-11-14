/**
 * Exercise 16: Graph Depth-First Search (DFS)
 * Difficulty: **** (4/5)
 * 
 * Implement a graph representation using an adjacency list and perform
 * a depth-first search traversal starting from a given node.
 * 
 * Input:
 * - First line: number of nodes (n)
 * - Second line: number of edges (m)
 * - Next m lines: edges (u v) representing an edge from u to v
 * - Last line: starting node for DFS
 * 
 * Output:
 * - Print all visited nodes in DFS order, space-separated, ending with newline
 */

#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<int>> adj;
    
    void dfsHelper(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }
    
public:
    Graph(int n) : numNodes(n), adj(n) {}
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }
    
    void dfs(int start) {
        vector<bool> visited(numNodes, false);
        dfsHelper(start, visited);
    }
};

int main() {
    int n;
    cin >> n;
    
    Graph graph(n);
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    
    int start;
    cin >> start;
    
    graph.dfs(start);
    
    cout << "\n";
    
    return 0;
}
