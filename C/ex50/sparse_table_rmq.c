/**
 * Exercise 50: Sparse Table — Range Minimum Query (RMQ)
 * Difficulty: ***** (5/5)
 *
 * Build a Sparse Table to answer Range Minimum Query on a static array.
 *
 * Preprocessing:
 * - Build st[k][i] = min on interval [i, i + 2^k - 1]
 * - Precompute logs to answer queries in O(1)
 *
 * Query (l, r):
 * - Let len = r-l+1, k = floor(log2(len))
 * - Answer = min(st[k][l], st[k][r-2^k+1])
 *
 * Input:
 * - First line: N Q
 * - Second line: N integers
 * - Next Q lines: l r (0-indexed, inclusive)
 *
 * Output:
 * - For each query: print minimum value in [l, r]
 */

#include <stdio.h>
#include <stdlib.h>

// TODO: Precompute logs
// TODO: Build sparse table
// TODO: Answer queries

int main(void)
{
    int n, q;
    if (scanf("%d %d", &n, &q) != 2)
        return 0;

    // TODO: Read array

    // TODO: Precompute log table and sparse table

    // TODO: Answer queries

    return 0;
}
