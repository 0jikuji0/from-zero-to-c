/**
 * Exercise 33: Kruskal's Algorithm (Minimum Spanning Tree)
 * Difficulty: ***** (5/5)
 * 
 * Implement Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a weighted graph.
 * Use Disjoint Set Union (Union-Find) to detect cycles.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v weight) representing undirected weighted edges
 * 
 * Output:
 * - Print total weight of MST
 * - Print all edges in MST
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class DSU {
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        
        if (xRoot == yRoot) {
            return;
        }
        
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    
    vector<Edge> mst;
    long long total_weight = 0;
    
    for (const Edge& edge : edges) {
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            mst.push_back(edge);
            total_weight += edge.weight;
            dsu.unionSets(edge.u, edge.v);
            
            if (mst.size() == n - 1) {
                break;
            }
        }
    }
    
    cout << "Total MST weight: " << total_weight << endl;
    cout << "MST edges:" << endl;
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << ": " << edge.weight << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    kruskal(n, edges);
    
    return 0;
}
