/*
 * Selection Sort (Exercise 3) - Solution
 * Difficulty: ** (2/5)
 *
 * Solution: selection sort implementation.
 */

#include <stdio.h>

void selection_sort(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int tmp = a[i];
            a[i] = a[min_idx];
            a[min_idx] = tmp;
        }
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: expected a positive integer n\n");
        return 1;
    }
    int arr[1000];
    if (n > 1000) {
        fprintf(stderr, "Error: n too large (max 1000)\n");
        return 1;
    }
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: expected %d integers\n", n);
            return 1;
        }
    }
    selection_sort(arr, n);
    for (int i = 0; i < n; ++i) {
        printf("%d%s", arr[i], (i+1==n) ? "\n" : " ");
    }
    return 0;
}
