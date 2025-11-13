/*
 * Prime Sieve (Exercise 6)
 * Difficulty: ** (2/5)
 *
 * Problem: read an integer n (0 <= n <= 1000000) and print the number of
 * prime numbers <= n using the Sieve of Eratosthenes or another method.
 *
 * Input format:
 * n
 *
 * Output format:
 * count
 *
 * Example:
 * Input:
 * 10
 * Output:
 * 4
 * (primes <= 10 are 2, 3, 5, 7)
 */

#include <stdio.h>

/* TODO: implement int count_primes(int n) which returns the number of
 * prime numbers <= n. You can use a char array to mark non-primes and the
 * standard O(n log log n) sieve algorithm.
 */

int count_primes(int n) {
    // TODO: student implementation
    (void)n;
    return 0;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n < 0) return 0;
    printf("%d\n", count_primes(n));
    return 0;
}
