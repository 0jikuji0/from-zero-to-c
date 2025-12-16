/**
 * Exercise 50: Sparse Table — Range Minimum Query (RMQ)
 * Difficulty: ***** (5/5)
 *
 * Solution:
 * - Precompute log2 values
 * - Build sparse table
 * - Answer queries in O(1)
 */

#include <stdio.h>
#include <stdlib.h>

static int computeLog(int n)
{
    int lg = 1;
    while ((1 << lg) <= n)
        lg++;
    return lg;
}

static int min2(int a, int b)
{
    return a < b ? a : b;
}

int main(void)
{
    int n, q;
    if (scanf("%d %d", &n, &q) != 2)
        return 0;

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int *lg2 = (int *)malloc((n + 1) * sizeof(int));
    lg2[0] = 0;
    if (n >= 1)
        lg2[1] = 0;
    for (int i = 2; i <= n; i++)
        lg2[i] = lg2[i / 2] + 1;

    int K = computeLog(n);

    // st[k][i] stored as st[k*(n) + i]
    int *st = (int *)malloc(K * n * sizeof(int));

    for (int i = 0; i < n; i++)
        st[0 * n + i] = arr[i];

    for (int k = 1; k < K; k++) {
        int len = 1 << k;
        int half = len >> 1;
        for (int i = 0; i + len <= n; i++) {
            st[k * n + i] = min2(st[(k - 1) * n + i], st[(k - 1) * n + (i + half)]);
        }
    }

    for (int qi = 0; qi < q; qi++) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l > r) {
            int tmp = l;
            l = r;
            r = tmp;
        }
        int len = r - l + 1;
        int k = lg2[len];
        int rightStart = r - (1 << k) + 1;
        int ans = min2(st[k * n + l], st[k * n + rightStart]);
        printf("%d\n", ans);
    }

    free(arr);
    free(lg2);
    free(st);
    return 0;
}
