// Max Subarray (Exercise 12) - Solution
// Find the maximum sum of a contiguous subarray using Kadane's algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    long maxSum = arr[0];
    long currentSum = arr[0];
    
    for (int i = 1; i < n; i++) {
        currentSum = (arr[i] > currentSum + arr[i]) ? arr[i] : currentSum + arr[i];
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    
    printf("%ld\n", maxSum);
    
    free(arr);
    return 0;
}
