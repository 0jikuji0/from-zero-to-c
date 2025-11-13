/*
 * Pointer Swap (Exercise 10)
 * Difficulty: * (1 star) - Easy
 *
 * Problem: read two integers a and b, then swap them using pointers.
 * Print the swapped values.
 *
 * Input format:
 * a b
 *
 * Output format:
 * a b  (swapped)
 *
 * Hints / TODOs for students:
 * - TODO 1: read two integers a and b from stdin.
 * - TODO 2: implement a swap function that takes pointers to two integers.
 * - TODO 3: call swap and print the result.
 *
 * Example of pointer usage: swap(*p1, *p2) by manipulating the dereferenced values.
 */

#include <stdio.h>

/* TODO: implement void swap(int *p1, int *p2) that swaps two integers via pointers */

int main(void) {
    int a, b;

    // TODO 1: read two integers a and b
    if (scanf("%d %d", &a, &b) != 2) return 0;

    // TODO 2: call swap function
    // swap(&a, &b);

    // TODO 3: print swapped values
    printf("%d %d\n", a, b);

    return 0;
}
