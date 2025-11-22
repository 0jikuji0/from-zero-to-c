/**
 * Exercise 30: Bellman-Ford Algorithm (Shortest Path with Negative Weights)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Bellman-Ford algorithm to find shortest paths from a source vertex
 * to all other vertices in a weighted graph, including graphs with negative edge weights.
 * Also detect negative weight cycles.
 * 
 * Input:
 * - First line: number of vertices (n), edges (m), source vertex (s)
 * - Next m lines: edges (u v weight) representing directed weighted edges
 * 
 * Output:
 * - If negative cycle exists: print "Negative cycle detected"
 * - Otherwise: print shortest distance from source to each vertex
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int u, v, weight;
};

const long long INF = numeric_limits<long long>::max();

bool bellmanFord(int n, vector<Edge>& edges, int source, vector<long long>& dist) {
    dist.assign(n, INF);
    dist[source] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }
    
    for (auto& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.weight < dist[edge.v]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n, m, source;
    cin >> n >> m >> source;
    
    vector<Edge> edges(m);
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    vector<long long> dist;
    
    if (!bellmanFord(n, edges, source, dist)) {
        cout << "Negative cycle detected" << endl;
    } else {
        cout << "Shortest distances from vertex " << source << ":" << endl;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INF) {
                cout << "Vertex " << i << ": INF" << endl;
            } else {
                cout << "Vertex " << i << ": " << dist[i] << endl;
            }
        }
    }
    
    return 0;
}
