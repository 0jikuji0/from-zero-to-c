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

using System;
using System.Collections.Generic;

class SegmentTree {
    private long[] tree;
    private int size;
    
    public SegmentTree(int[] arr) {
        size = arr.Length;
        tree = new long[4 * size];
        Build(arr, 1, 0, size - 1);
    }
    
    private void Build(int[] arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            Build(arr, 2 * node, start, mid);
            Build(arr, 2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    public void Update(int idx, int val) {
        Update(1, 0, size - 1, idx, val);
    }
    
    private void Update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                Update(2 * node, start, mid, idx, val);
            } else {
                Update(2 * node + 1, mid + 1, end, idx, val);
            }
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    
    public long Query(int l, int r) {
        return Query(1, 0, size - 1, l, r);
    }
    
    private long Query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        
        if (l <= start && end <= r) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        long p1 = Query(2 * node, start, mid, l, r);
        long p2 = Query(2 * node + 1, mid + 1, end, l, r);
        
        return p1 + p2;
    }
}

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine());
        
        string[] arrStr = Console.ReadLine().Split();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = int.Parse(arrStr[i]);
        }
        
        SegmentTree st = new SegmentTree(arr);
        
        int m = int.Parse(Console.ReadLine());
        
        for (int i = 0; i < m; i++) {
            string[] parts = Console.ReadLine().Split();
            
            if (parts[0][0] == 'q') {  // query
                int l = int.Parse(parts[1]);
                int r = int.Parse(parts[2]);
                long result = st.Query(l, r);
                Console.WriteLine(result);
            } else {  // update
                int idx = int.Parse(parts[1]);
                int val = int.Parse(parts[2]);
                st.Update(idx, val);
            }
        }
    }
}
