/**
 * Exercise 22: Merge Sort Algorithm
 * Difficulty: *** (3/5)
 * 
 * Implement the merge sort algorithm to sort an array of integers.
 * Merge sort is a divide-and-conquer sorting algorithm with O(n log n) time complexity.
 * 
 * Input:
 * - First line: number of elements (n)
 * - Second line: n integers to be sorted
 * 
 * Output:
 * - Print the sorted array in ascending order (space-separated)
 */

#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    
    int* leftArr = malloc(sizeof(int) * leftSize);
    int* rightArr = malloc(sizeof(int) * rightSize);
    
    for (int i = 0; i < leftSize; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < rightSize; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }
    
    int i = 0, j = 0, k = left;
    
    while (i < leftSize && j < rightSize) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    
    while (i < leftSize) {
        arr[k++] = leftArr[i++];
    }
    
    while (j < rightSize) {
        arr[k++] = rightArr[j++];
    }
    
    free(leftArr);
    free(rightArr);
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    mergeSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    free(arr);
    return 0;
}
