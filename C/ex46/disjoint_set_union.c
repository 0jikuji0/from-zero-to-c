/**
 * Exercise 46: Disjoint Set Union (Union-Find)
 * Difficulty: ***** (5/5)
 * 
 * Implement a Disjoint Set Union (DSU) data structure with union by rank
 * and path compression optimizations. This structure efficiently handles:
 * - MakeSet(x): Create a set containing only x
 * - Find(x): Find the representative (root) of the set containing x
 * - Union(x, y): Merge the sets containing x and y
 * - Connected(x, y): Check if x and y are in the same set
 * 
 * With optimizations, operations run in nearly O(1) amortized time.
 * 
 * Applications:
 * - Kruskal's MST algorithm
 * - Connected components in graphs
 * - Cycle detection
 * 
 * Input:
 * - First line: number of elements N (0 to N-1)
 * - Second line: number of operations Q
 * - Next Q lines: operation commands
 *   - "union X Y": union sets containing X and Y
 *   - "find X": find and print representative of X
 *   - "connected X Y": print "true" if connected, else "false"
 * 
 * Output:
 * - For "find X": print the representative element
 * - For "connected X Y": print "true" or "false"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *parent;
    int *rank;
    int n;
} DSU;

// TODO: Initialize DSU with n elements (each element is its own set)

// TODO: Implement find with path compression

// TODO: Implement union by rank

// TODO: Check if two elements are connected (same set)

int main() {
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    getchar();
    
    // TODO: Initialize DSU
    
    for (int i = 0; i < q; i++) {
        char operation[20];
        scanf("%s", operation);
        
        // TODO: Handle operations based on command
    }
    
    return 0;
}
