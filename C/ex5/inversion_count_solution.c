/*
 * Inversion Count (Exercise 5) - Solution
 * Difficulty: *** (3/5)
 *
 * Solution: count inversions using merge sort and return a 64-bit count.
 */

#include <stdio.h>
#include <stdlib.h>

static long long merge_count(int *a, int *tmp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv = 0;
    while (i < mid && j <= right) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
            inv += (mid - i); // all remaining in left half are inversions
        }
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j <= right) tmp[k++] = a[j++];
    for (i = left; i <= right; ++i) a[i] = tmp[i];
    return inv;
}

static long long sort_count(int *a, int *tmp, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long inv = 0;
    inv += sort_count(a, tmp, left, mid);
    inv += sort_count(a, tmp, mid+1, right);
    inv += merge_count(a, tmp, left, mid+1, right);
    return inv;
}

long long count_inversions(int *a, int n) {
    if (n <= 1) return 0;
    int *tmp = malloc(sizeof(int) * n);
    if (!tmp) return 0; // fail-safe: return 0 if allocation fails
    long long res = sort_count(a, tmp, 0, n-1);
    free(tmp);
    return res;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Error: expected non-negative integer n\n");
        return 1;
    }
    if (n > 100000) {
        fprintf(stderr, "Error: n too large (max 100000)\n");
        return 1;
    }
    int *arr = malloc(sizeof(int) * n);
    if (!arr && n > 0) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error: expected %d integers\n", n);
            free(arr);
            return 1;
        }
    }
    long long inv = count_inversions(arr, n);
    printf("%lld\n", inv);
    free(arr);
    return 0;
}
