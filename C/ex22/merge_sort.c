#include <stdio.h>
#include <stdlib.h>

// TODO: Implement merge sort algorithm
// Hint: Use divide-and-conquer to recursively sort and merge

// TODO: Implement merge function to combine two sorted subarrays

// TODO: Print the sorted array

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // TODO: Call merge sort function
    
    // TODO: Print sorted array
    
    free(arr);
    return 0;
}
