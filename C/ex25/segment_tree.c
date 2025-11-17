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

// TODO: Define segment tree structure

// TODO: Implement build function to construct the segment tree

// TODO: Implement query function for range sum queries

// TODO: Implement update function for point updates

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // TODO: Build segment tree
    
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        char op[20];
        scanf("%s", op);
        
        if (op[0] == 'q') {  // query
            int l, r;
            scanf("%d %d", &l, &r);
            // TODO: Execute query
        } else {  // update
            int idx, val;
            scanf("%d %d", &idx, &val);
            // TODO: Execute update
        }
    }
    
    free(arr);
    return 0;
}
