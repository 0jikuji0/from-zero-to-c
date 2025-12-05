/**
 * Exercise 45: Fenwick Tree (Binary Indexed Tree)
 * Difficulty: ***** (5/5)
 * 
 * Implement a Fenwick Tree (Binary Indexed Tree) for efficient range queries
 * and point updates on an array. This data structure supports:
 * - Update(index, value): Add value to element at index (1-indexed)
 * - Query(index): Get prefix sum from 1 to index
 * - RangeQuery(left, right): Get sum of elements from left to right
 * 
 * Both operations run in O(log n) time, making it efficient for problems
 * requiring frequent updates and range sum queries.
 * 
 * The tree uses bit manipulation to navigate parent-child relationships:
 * - Parent: index - (index & -index)
 * - Next: index + (index & -index)
 * 
 * Input:
 * - First line: size of array N
 * - Second line: N space-separated integers (initial array values)
 * - Third line: number of operations Q
 * - Next Q lines: operation commands
 *   - "update I V": add V to element at index I (1-indexed)
 *   - "query I": get prefix sum from 1 to I
 *   - "range L R": get sum from L to R (inclusive)
 * 
 * Output:
 * - For "query I": print the prefix sum
 * - For "range L R": print the range sum
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *tree;
    int n;
} FenwickTree;

// TODO: Implement LSB function: return index & -index

// TODO: Implement update helper: add delta to tree[index] and propagate to parents

// TODO: Implement query helper: compute prefix sum from 1 to index

// TODO: Implement initialization: build tree from initial array

// TODO: Implement update: add value to position index

// TODO: Implement query: return prefix sum from 1 to index

// TODO: Implement rangeQuery: return sum from left to right

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // TODO: Initialize Fenwick tree
    
    int q;
    scanf("%d", &q);
    getchar();
    
    for (int i = 0; i < q; i++) {
        char operation[10];
        scanf("%s", operation);
        
        // TODO: Handle operations based on command
    }
    
    free(arr);
    return 0;
}
