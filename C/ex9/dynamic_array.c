/*
 * Dynamic Array Modification (Exercise 11)
 * Difficulty: ** (2 stars) - Easy-Medium
 *
 * Problem: read n integers into a dynamically allocated array, then read
 * an index i and a new value v. Replace array[i] with v and print the
 * entire modified array.
 *
 * Input format:
 * n
 * a1 a2 ... an
 * i v
 *
 * Output format:
 * a1 a2 ... an (with a[i] replaced by v)
 *
 * Hints / TODOs for students:
 * - TODO 1: read n and allocate a dynamic array of size n.
 * - TODO 2: read n integers into the array using pointer arithmetic or indexing.
 * - TODO 3: read index i and value v.
 * - TODO 4: modify array[i] = v using either array indexing or pointer arithmetic.
 * - TODO 5: print the entire array.
 * - TODO 6: free the allocated memory.
 *
 * Key concept: pointers and dynamic memory (malloc/free) to manipulate arrays.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;

    // TODO 1: read n
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    // TODO 1 (continued): allocate dynamic array
    int *arr = NULL;  // TODO: malloc(sizeof(int) * n);
    if (!arr) return 1;

    // TODO 2: read n integers into the array
    for (int i = 0; i < n; ++i) {
        // TODO: scanf("%d", &arr[i]); or *(arr + i)
    }

    // TODO 3: read index i and value v
    int i, v;
    if (scanf("%d %d", &i, &v) != 2) {
        free(arr);
        return 0;
    }

    // TODO 4: check bounds and modify array[i]
    if (i >= 0 && i < n) {
        // TODO: arr[i] = v; or *(arr + i) = v;
    }

    // TODO 5: print the entire modified array
    for (int j = 0; j < n; ++j) {
        // TODO: printf("%d%s", arr[j], (j+1==n) ? "\n" : " ");
    }

    // TODO 6: free the array
    // TODO: free(arr);

    return 0;
}
