/*
 * Two Sum (Exercise 9)
 * Difficulty: ** (2/5)
 *
+ * Problem: given an array of n integers and a target value t, determine
 * whether there exist two distinct indices i and j such that a[i] + a[j] = t.
 * If a pair exists, print the two 1-based indices (in any order). Otherwise
 * print "NO".
 *
 * Input format:
 * n t
 * a1 a2 ... an
 *
 * Output format:
 * i j
 * or
 * NO
 *
 * Hints / steps for students:
 * - Option A: use a hash table (map value -> original index) to find complements
 *   in O(n) expected time.
 * - Option B: pair each element with its original index, sort by value, then
 *   use two pointers to find a pair with sum t (O(n log n)).
 * - Remember to print 1-based indices and to handle duplicates correctly.
 */

#include <stdio.h>
#include <stdlib.h>

/* TODO 1: read integers n and t from stdin
 * TODO 2: read the array of n integers (store values and optionally indices)
 * TODO 3: implement one of the suggested algorithms to find two indices i,j
 * TODO 4: print the two 1-based indices separated by a space, or print "NO"
 *
 * Minimal skeleton below — fill the TODOs.
 */

int main(void) {
    int n;
    long long t;

    // TODO: read n and t (e.g., if (scanf("%d %lld", &n, &t) != 2) return 0; )

    // TODO: allocate array(s) and read n integers into them

    // TODO: choose and implement an algorithm (hash table or sort+two pointers)

    // TODO: if a valid pair is found, print: printf("%d %d\n", i, j);
    // otherwise, print: printf("NO\n");

    return 0;
}
