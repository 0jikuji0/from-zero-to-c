/*
 * Inversion Count (Exercise 5)
 * Difficulty: ***** (5 stars) - Very hard
 *
 * Task: implement `count_inversions` which counts the number of inversions in an
 * integer array (pairs i<j with a[i] > a[j]) using a divide-and-conquer approach
 * (merge sort based). The skeleton below reads n and the array, then prints the
 * number of inversions.
 */

#include <stdio.h>
#include <stdlib.h>

/* TODOs: students should implement a merge-sort based inversion counting.
 * Hints / steps:
 *  1) Implement a recursive function that sorts a subarray [left..right] and
 *     returns the number of inversions inside that subarray.
 *  2) The recursive routine should:
 *     - split the range into [left..mid] and [mid+1..right]
 *     - count inversions in left and right recursively
 *     - merge the two sorted halves into a temporary array and count cross inversions
 *       during the merge: when right element is placed before left element,
 *       add (mid - i + 1) to the inversion count for the remaining left elements.
 *  3) Be careful with indices and use a 64-bit counter (long long) for totals.
 */

long long count_inversions(int *a, int n) {
    /* TODO: implement merge-sort based inversion counting.
     * Suggested helper functions:
     *  - long long sort_count(int *a, int *tmp, int left, int right)
     *  - long long merge_count(int *a, int *tmp, int left, int mid, int right)
     * Use malloc to allocate tmp array of size n before calling the recursive helper.
     */
    (void)a; (void)n;
    return 0LL; /* placeholder */
}

int main(void) {
    /* TODO: read n, validate, allocate array, read n integers, call count_inversions
     * and print the result. Use long long for the inversion count output.
     */
    return 0;
}
