/**
 * Exercise 24: Segment Tree (Range Sum Query)
 * Difficulty: ***** (5/5)
 * 
 * Implement a segment tree to support range sum queries and point updates.
 * 
 * Input:
 * - First line: number of elements (n)
 * - Second line: array of n integers
 * - Third line: number of operations
 * - Next lines: operations ("query l r" or "update idx val")
 * 
 * Output:
 * - For each query: print the sum of elements from index l to r
 */

#include <bits/stdc++.h>
using namespace std;

// TODO: Define segment tree structure

// TODO: Implement build function to construct the segment tree

// TODO: Implement query function for range sum queries

// TODO: Implement update function for point updates

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // TODO: Build segment tree
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        
        if (op[0] == 'q') {  // query
            int l, r;
            cin >> l >> r;
            // TODO: Execute query
        } else {  // update
            int idx, val;
            cin >> idx >> val;
            // TODO: Execute update
        }
    }
    
    return 0;
}
