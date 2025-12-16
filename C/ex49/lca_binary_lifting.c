/**












































 * Difficulty: ***** (5/5)
 *
 * Given a tree with N nodes (1-indexed) and Q queries, answer each query:
 *   LCA(u, v) = the lowest (deepest) node that is an ancestor of both u and v.
 *
 * Use binary lifting (sparse parents) to preprocess in O(N log N) and answer
 * each query in O(log N).
 *
 * Input:
 * - First line: N Q
 * - Next N-1 lines: edges a b (undirected)
 * - Next Q lines: queries u v
 *
 * Output:
 * - For each query, print the LCA(u, v) on its own line.
 *
 * Notes:
 * - Root the tree at node 1.
 * - Constraints are not fixed; implement efficiently.
 */

#include <stdio.h>
#include <stdlib.h>

// TODO: Implement adjacency list (arrays head/to/next)
// TODO: Build parent[k][v] table (binary lifting)
// TODO: Compute depth[] using BFS/DFS from root
// TODO: Implement lca(u, v)

int main(void) {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) {
        return 0;
    }

    // TODO: Read edges and build adjacency list

    // TODO: Preprocess (depth + parent table)

    // TODO: Answer queries

    return 0;
}
