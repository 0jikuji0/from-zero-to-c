// Fibonacci (Exercise 10) - Solution
// Generate the n-th Fibonacci number.

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("0\n");
        return 0;
    }
    
    if (n == 1) {
        printf("1\n");
        return 0;
    }
    
    long fib0 = 0, fib1 = 1;
    for (int i = 2; i <= n; i++) {
        long temp = fib0 + fib1;
        fib0 = fib1;
        fib1 = temp;
    }
    
    printf("%ld\n", fib1);
    
    return 0;
}
