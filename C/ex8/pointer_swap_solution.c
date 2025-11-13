/*
 * Pointer Swap (Exercise 10) - Solution
 * Demonstrates simple pointer dereferencing and value swapping.
 */

#include <stdio.h>

void swap(int *p1, int *p2) {
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main(void) {
    int a, b;
    if (scanf("%d %d", &a, &b) != 2) return 0;
    swap(&a, &b);
    printf("%d %d\n", a, b);
    return 0;
}
