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

class SegmentTree {
private:
    vector<long long> tree;
    int size;
    
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node, start, mid);
            build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node, start, mid, idx, val);
            } else {
                update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    long long query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        long long p1 = query(2 * node, start, mid, l, r);
        long long p2 = query(2 * node + 1, mid + 1, end, l, r);
        
        return p1 + p2;
    }
    
public:
    SegmentTree(vector<int>& arr) {
        size = arr.size();
        tree.resize(4 * size, 0);
        build(arr, 1, 0, size - 1);
    }
    
    void update(int idx, int val) {
        update(1, 0, size - 1, idx, val);
    }
    
    long long query(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    SegmentTree st(arr);
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        string op;
        cin >> op;
        
        if (op[0] == 'q') {  // query
            int l, r;
            cin >> l >> r;
            long long result = st.query(l, r);
            cout << result << "\n";
        } else {  // update
            int idx, val;
            cin >> idx >> val;
            st.update(idx, val);
        }
    }
    
    return 0;
}
