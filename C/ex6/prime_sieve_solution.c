/*
 * Prime Sieve (Exercise 8) - Solution
 * Uses Sieve of Eratosthenes to count primes up to n (n <= 1e6).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_primes(int n) {
    if (n < 2) return 0;
    char *is_prime = malloc((size_t)n + 1);
    if (!is_prime) return 0;
    memset(is_prime, 1, (size_t)n + 1);
    is_prime[0] = is_prime[1] = 0;
    for (int p = 2; (long long)p * p <= n; ++p) {
        if (is_prime[p]) {
            for (int q = p * p; q <= n; q += p) is_prime[q] = 0;
        }
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++i) cnt += is_prime[i];
    free(is_prime);
    return cnt;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n < 0) return 0;
    printf("%d\n", count_primes(n));
    return 0;
}
