/*
 * Add (Exercise 1) - Solution
 * Difficulty: * (1/5)
 *
 * Completed solution: simple sum of two integers.
 */

#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int main(void) {
    int x, y;
    if (scanf("%d %d", &x, &y) != 2) {
        fprintf(stderr, "Error: expected two integers\n");
        return 1;
    }
    printf("%d\n", add(x, y));
    return 0;
}
