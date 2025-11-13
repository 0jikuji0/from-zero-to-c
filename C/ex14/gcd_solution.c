// GCD (Exercise 14) - Solution
// Find the Greatest Common Divisor of two numbers.

#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    printf("%d\n", a);
    
    return 0;
}
