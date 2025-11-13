// Is Prime (Exercise 11) - Solution
// Check if a given number is prime.

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n < 2) {
        printf("0\n");
        return 0;
    }
    
    if (n == 2) {
        printf("1\n");
        return 0;
    }
    
    if (n % 2 == 0) {
        printf("0\n");
        return 0;
    }
    
    int limit = (int)sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            printf("0\n");
            return 0;
        }
    }
    
    printf("1\n");
    return 0;
}
