/**
 * Exercise 25: Segment Tree (Range Sum Query)
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long* tree;
    int size;
} SegmentTree;

SegmentTree* createSegmentTree(int n) {
    SegmentTree* st = malloc(sizeof(SegmentTree));
    st->size = 4 * n;
    st->tree = malloc(sizeof(long long) * st->size);
    
    for (int i = 0; i < st->size; i++) {
        st->tree[i] = 0;
    }
    
    return st;
}

void build(SegmentTree* st, int* arr, int node, int start, int end) {
    if (start == end) {
        st->tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(st, arr, 2 * node, start, mid);
        build(st, arr, 2 * node + 1, mid + 1, end);
        st->tree[node] = st->tree[2 * node] + st->tree[2 * node + 1];
    }
}

void update(SegmentTree* st, int node, int start, int end, int idx, int val) {
    if (start == end) {
        st->tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(st, 2 * node, start, mid, idx, val);
        } else {
            update(st, 2 * node + 1, mid + 1, end, idx, val);
        }
        st->tree[node] = st->tree[2 * node] + st->tree[2 * node + 1];
    }
}

long long query(SegmentTree* st, int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    
    if (l <= start && end <= r) {
        return st->tree[node];
    }
    
    int mid = (start + end) / 2;
    long long p1 = query(st, 2 * node, start, mid, l, r);
    long long p2 = query(st, 2 * node + 1, mid + 1, end, l, r);
    
    return p1 + p2;
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    SegmentTree* st = createSegmentTree(n);
    build(st, arr, 1, 0, n - 1);
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        char op[20];
        scanf("%s", op);
        
        if (op[0] == 'q') {  // query
            int l, r;
            scanf("%d %d", &l, &r);
            long long result = query(st, 1, 0, n - 1, l, r);
            printf("%lld\n", result);
        } else {  // update
            int idx, val;
            scanf("%d %d", &idx, &val);
            update(st, 1, 0, n - 1, idx, val);
        }
    }
    
    free(arr);
    free(st->tree);
    free(st);
    
    return 0;
}
