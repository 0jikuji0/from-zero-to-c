/*
 * Two Sum (Exercise 9) - Solution
 * Uses sorting with indices and two-pointer scan to find a pair summing to t.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct { long long val; int idx; } Item;

int cmp_item(const void *p, const void *q) {
    const Item *a = p; const Item *b = q;
    if (a->val < b->val) return -1;
    if (a->val > b->val) return 1;
    return 0;
}

int main(void) {
    int n;
    long long t;
    if (scanf("%d %lld", &n, &t) != 2) return 0;
    Item *arr = malloc(sizeof(Item) * n);
    if (!arr && n>0) return 0;
    for (int i = 0; i < n; ++i) {
        long long x; scanf("%lld", &x);
        arr[i].val = x; arr[i].idx = i+1; // 1-based index
    }
    qsort(arr, n, sizeof(Item), cmp_item);
    int l = 0, r = n-1;
    while (l < r) {
        long long s = arr[l].val + arr[r].val;
        if (s == t) {
            printf("%d %d\n", arr[l].idx, arr[r].idx);
            free(arr);
            return 0;
        } else if (s < t) ++l; else --r;
    }
    printf("NO\n");
    free(arr);
    return 0;
}
