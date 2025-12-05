/**
 * Exercise 45: Fenwick Tree (Binary Indexed Tree)
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Fenwick Tree for efficient range queries and updates.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *tree;
    int n;
} FenwickTree;

int LSB(int index) {
    return index & -index;
}

void updateHelper(FenwickTree *ft, int index, int delta) {
    while (index <= ft->n) {
        ft->tree[index] += delta;
        index += LSB(index);
    }
}

int queryHelper(FenwickTree *ft, int index) {
    int sum = 0;
    while (index > 0) {
        sum += ft->tree[index];
        index -= LSB(index);
    }
    return sum;
}

FenwickTree* createFenwickTree(int *arr, int n) {
    FenwickTree *ft = (FenwickTree*)malloc(sizeof(FenwickTree));
    ft->n = n;
    ft->tree = (int*)calloc(n + 1, sizeof(int));
    
    // Build tree from array
    for (int i = 0; i < n; i++) {
        updateHelper(ft, i + 1, arr[i]);
    }
    
    return ft;
}

void update(FenwickTree *ft, int index, int value) {
    updateHelper(ft, index, value);
}

int query(FenwickTree *ft, int index) {
    return queryHelper(ft, index);
}

int rangeQuery(FenwickTree *ft, int left, int right) {
    if (left > 1) {
        return queryHelper(ft, right) - queryHelper(ft, left - 1);
    }
    return queryHelper(ft, right);
}

void freeFenwickTree(FenwickTree *ft) {
    free(ft->tree);
    free(ft);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    FenwickTree *ft = createFenwickTree(arr, n);
    
    int q;
    scanf("%d", &q);
    getchar();
    
    for (int i = 0; i < q; i++) {
        char operation[10];
        scanf("%s", operation);
        
        if (strcmp(operation, "update") == 0) {
            int index, value;
            scanf("%d %d", &index, &value);
            update(ft, index, value);
        } else if (strcmp(operation, "query") == 0) {
            int index;
            scanf("%d", &index);
            printf("%d\n", query(ft, index));
        } else if (strcmp(operation, "range") == 0) {
            int left, right;
            scanf("%d %d", &left, &right);
            printf("%d\n", rangeQuery(ft, left, right));
        }
    }
    
    free(arr);
    freeFenwickTree(ft);
    return 0;
}
