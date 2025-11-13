/*
 * Dynamic Array Modification (Exercise 11) - Solution
 * Demonstrates dynamic memory allocation, pointer arithmetic, and array manipulation.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = malloc(sizeof(int) * n);
    if (!arr) return 1;

    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 0;
        }
    }

    int i, v;
    if (scanf("%d %d", &i, &v) != 2) {
        free(arr);
        return 0;
    }

    if (i >= 0 && i < n) {
        arr[i] = v;
    }

    for (int j = 0; j < n; ++j) {
        printf("%d%s", arr[j], (j+1==n) ? "\n" : " ");
    }

    free(arr);
    return 0;
}
