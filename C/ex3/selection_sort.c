/*
 * Selection Sort (Exercise 3)
 * Difficulty: *** (3 stars) - Easy
 *
 * Task: implement `selection_sort` to sort an array of integers in ascending order.
 * The program reads n followed by n integers and prints the sorted array.
 */

#include <stdio.h>

/* TODOs: students should implement selection_sort and the minimal I/O.
 * Hints / steps for selection sort:
 *  1) For each index i from 0 to n-2, find the index min_idx of the smallest
 *     element in the range [i..n-1].
 *  2) Swap a[i] and a[min_idx] if min_idx != i.
 *  3) Repeat until array is sorted.
 */

/* TODO 1: implement selection sort following the steps above. */
void selection_sort(int *a, int n) {
    /* TODO: write the outer loop for i, inner loop for j to find min_idx,
     * and swap logic. */
    (void)a; (void)n; /* placeholders to avoid warnings */
}

int main(void) {
    /* TODO: read integer n, validate it (n > 0 and n <= 1000), then read n integers
     * into arr. If input is invalid, print an error and return non-zero.
     * After reading, call selection_sort(arr, n) and print the sorted array.
     */
    return 0;
}
