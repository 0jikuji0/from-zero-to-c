/**
 * Exercise 26: Graph Coloring (Chromatic Number)
 * Difficulty: ***** (5/5)
 * 
 * Implement graph coloring using backtracking to find the chromatic number.
 * The chromatic number is the minimum number of colors needed to color a graph
 * such that no two adjacent vertices have the same color.
 * 
 * Input:
 * - First line: number of vertices (n) and edges (m)
 * - Next m lines: edges (u v) representing connections
 * 
 * Output:
 * - Print the chromatic number
 * - Print a valid coloring assignment for each vertex
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> color;

bool isSafe(int vertex, int c) {
    for (int neighbor : adj[vertex]) {
        if (color[neighbor] == c) {
            return false;
        }
    }
    return true;
}

bool colorGraphUtil(int vertex, int maxColors) {
    if (vertex == n) {
        return true;
    }
    
    for (int c = 1; c <= maxColors; c++) {
        if (isSafe(vertex, c)) {
            color[vertex] = c;
            
            if (colorGraphUtil(vertex + 1, maxColors)) {
                return true;
            }
            
            color[vertex] = 0;
        }
    }
    
    return false;
}

int findChromaticNumber() {
    color.assign(n, 0);
    
    for (int numColors = 1; numColors <= n; numColors++) {
        if (colorGraphUtil(0, numColors)) {
            return numColors;
        }
        color.assign(n, 0);
    }
    
    return n;
}

int main() {
    int m;
    cin >> n >> m;
    
    adj.resize(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int chromaticNum = findChromaticNumber();
    
    cout << "Chromatic Number: " << chromaticNum << endl;
    cout << "Coloring: ";
    for (int i = 0; i < n; i++) {
        cout << color[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
