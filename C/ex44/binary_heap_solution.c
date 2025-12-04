/**
 * Exercise 44: Binary Min-Heap
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing a Min-Heap with array-based representation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

void initHeap(MinHeap *heap) {
    heap->size = 0;
}

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return 2 * i + 1;
}

int rightChild(int i) {
    return 2 * i + 2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(MinHeap *heap, int index) {
    while (index > 0 && heap->data[parent(index)] > heap->data[index]) {
        swap(&heap->data[index], &heap->data[parent(index)]);
        index = parent(index);
    }
}

void heapifyDown(MinHeap *heap, int index) {
    int minIndex = index;
    int left = leftChild(index);
    int right = rightChild(index);
    
    if (left < heap->size && heap->data[left] < heap->data[minIndex]) {
        minIndex = left;
    }
    
    if (right < heap->size && heap->data[right] < heap->data[minIndex]) {
        minIndex = right;
    }
    
    if (index != minIndex) {
        swap(&heap->data[index], &heap->data[minIndex]);
        heapifyDown(heap, minIndex);
    }
}

void insert(MinHeap *heap, int value) {
    if (heap->size >= MAX_SIZE) {
        return; // Heap is full
    }
    
    heap->data[heap->size] = value;
    heapifyUp(heap, heap->size);
    heap->size++;
}

int extractMin(MinHeap *heap, int *result) {
    if (heap->size == 0) {
        return 0; // Empty heap
    }
    
    *result = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    
    if (heap->size > 0) {
        heapifyDown(heap, 0);
    }
    
    return 1;
}

int peek(MinHeap *heap, int *result) {
    if (heap->size == 0) {
        return 0; // Empty heap
    }
    
    *result = heap->data[0];
    return 1;
}

int isEmpty(MinHeap *heap) {
    return heap->size == 0;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    MinHeap heap;
    initHeap(&heap);
    
    for (int i = 0; i < n; i++) {
        char operation[10];
        scanf("%s", operation);
        
        if (strcmp(operation, "insert") == 0) {
            int value;
            scanf("%d", &value);
            insert(&heap, value);
        } else if (strcmp(operation, "extract") == 0) {
            int result;
            if (extractMin(&heap, &result)) {
                printf("%d\n", result);
            } else {
                printf("Heap is empty\n");
            }
        } else if (strcmp(operation, "peek") == 0) {
            int result;
            if (peek(&heap, &result)) {
                printf("%d\n", result);
            } else {
                printf("Heap is empty\n");
            }
        } else if (strcmp(operation, "empty") == 0) {
            printf("%s\n", isEmpty(&heap) ? "true" : "false");
        }
    }
    
    return 0;
}
