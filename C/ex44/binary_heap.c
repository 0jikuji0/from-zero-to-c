/**
 * Exercise 44: Binary Min-Heap
 * Difficulty: ***** (5/5)
 * 
 * Implement a Min-Heap data structure using an array-based representation.
 * A heap is a complete binary tree where each parent node has a value less
 * than or equal to its children (heap property).
 * 
 * Operations:
 * - Insert: Add element and bubble up to maintain heap property
 * - ExtractMin: Remove and return minimum (root), then bubble down
 * - Peek: Return minimum without removing
 * - IsEmpty: Check if heap is empty
 * 
 * Use array indexing for parent-child relationships:
 * - Parent of i: (i-1)/2
 * - Left child of i: 2*i + 1
 * - Right child of i: 2*i + 2
 * 
 * Input:
 * - First line: number of operations N
 * - Next N lines: operation commands
 *   - "insert X": insert value X
 *   - "extract": extract and print minimum
 *   - "peek": print minimum without removing
 *   - "empty": print "true" or "false"
 * 
 * Output:
 * - For "extract": print minimum value (or "Heap is empty")
 * - For "peek": print minimum value (or "Heap is empty")
 * - For "empty": print "true" or "false"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

// TODO: Initialize heap

// TODO: Get parent index

// TODO: Get left child index

// TODO: Get right child index

// TODO: Swap two elements

// TODO: Bubble up after insertion

// TODO: Bubble down after extraction

// TODO: Insert element

// TODO: Extract minimum element

// TODO: Peek at minimum

// TODO: Check if empty

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    MinHeap heap;
    heap.size = 0;
    
    for (int i = 0; i < n; i++) {
        char operation[10];
        scanf("%s", operation);
        
        // TODO: Handle operations based on command
    }
    
    return 0;
}
