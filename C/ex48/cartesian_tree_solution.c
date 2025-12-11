/**
 * Exercise 48: Cartesian Tree
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Cartesian Tree for RMQ queries.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CartNode {
    int value;
    int index;
    struct CartNode *left;
    struct CartNode *right;
    struct CartNode *parent;
} CartNode;

typedef struct {
    CartNode *root;
} CartesianTree;

CartNode* createNode(int value, int index) {
    CartNode *node = (CartNode*)malloc(sizeof(CartNode));
    node->value = value;
    node->index = index;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

CartesianTree* build(int *arr, int n) {
    CartesianTree *tree = (CartesianTree*)malloc(sizeof(CartesianTree));
    
    if (n == 0) {
        tree->root = NULL;
        return tree;
    }
    
    CartNode **stack = (CartNode**)malloc(n * sizeof(CartNode*));
    int top = -1;
    
    for (int i = 0; i < n; i++) {
        CartNode *node = createNode(arr[i], i);
        int last = -1;
        
        // Pop all elements greater than current element
        while (top >= 0 && stack[top]->value > node->value) {
            last = top;
            top--;
        }
        
        // Attach popped node as left child of current
        if (last != -1) {
            node->left = stack[last];
            stack[last]->parent = node;
        }
        
        // Attach current node as right child of top element
        if (top >= 0) {
            stack[top]->right = node;
            node->parent = stack[top];
        }
        
        stack[++top] = node;
    }
    
    // Root is at bottom of stack
    tree->root = stack[0];
    
    free(stack);
    return tree;
}

int rangeMin(CartNode *node, int l, int r) {
    if (!node) {
        return INT_MAX;
    }
    
    int nodeIdx = node->index;
    int result = INT_MAX;
    
    // If node is in range, include its value
    if (nodeIdx >= l && nodeIdx <= r) {
        result = node->value;
    }
    
    // Search in left subtree
    if (l <= nodeIdx) {
        int leftMin = rangeMin(node->left, l, r);
        if (leftMin < result) {
            result = leftMin;
        }
    }
    
    // Search in right subtree
    if (r >= nodeIdx) {
        int rightMin = rangeMin(node->right, l, r);
        if (rightMin < result) {
            result = rightMin;
        }
    }
    
    return result;
}

void inorderHelper(CartNode *node, int *first) {
    if (!node) {
        return;
    }
    
    inorderHelper(node->left, first);
    
    if (!(*first)) {
        printf(" ");
    }
    printf("%d", node->value);
    *first = 0;
    
    inorderHelper(node->right, first);
}

void inorder(CartesianTree *tree) {
    if (!tree->root) {
        printf("Empty tree\n");
    } else {
        int first = 1;
        inorderHelper(tree->root, &first);
        printf("\n");
    }
}

void freeTree(CartNode *node) {
    if (!node) {
        return;
    }
    
    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    CartesianTree *tree = build(arr, n);
    
    int q;
    scanf("%d", &q);
    getchar();
    
    for (int i = 0; i < q; i++) {
        char operation[10];
        scanf("%s", operation);
        
        if (strcmp(operation, "min") == 0) {
            int l, r;
            scanf("%d %d", &l, &r);
            int result = rangeMin(tree->root, l, r);
            printf("%d\n", result);
        } else if (strcmp(operation, "inorder") == 0) {
            inorder(tree);
        }
    }
    
    free(arr);
    freeTree(tree->root);
    free(tree);
    
    return 0;
}
