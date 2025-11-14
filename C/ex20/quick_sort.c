#include <stdio.h>
#include <stdlib.h>

// TODO: Implement the quicksort algorithm
// Hint: Use a partition function to divide the array

// TODO: Implement the partition function that places a pivot
// in its correct sorted position and returns the pivot index

// TODO: Print the array in sorted order (space-separated)

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // TODO: Call quicksort function
    
    // TODO: Print sorted array
    
    free(arr);
    return 0;
}
