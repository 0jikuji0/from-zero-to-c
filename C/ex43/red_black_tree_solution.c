/**
 * Exercise 43: Red-Black Tree
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Red-Black Tree with insertions and rebalancing.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 1
#define BLACK 0

typedef struct Node {
    int key;
    int color;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->color = RED; // New nodes are always red
    node->left = node->right = node->parent = NULL;
    return node;
}

void leftRotate(Node **root, Node *x) {
    Node *y = x->right;
    x->right = y->left;
    
    if (y->left != NULL)
        y->left->parent = x;
    
    y->parent = x->parent;
    
    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}

void rightRotate(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;
    
    if (x->right != NULL)
        x->right->parent = y;
    
    x->parent = y->parent;
    
    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    
    x->right = y;
    y->parent = x;
}

void fixViolation(Node **root, Node *z) {
    while (z != *root && z->parent->color == RED) {
        Node *parent = z->parent;
        Node *grandparent = parent->parent;
        
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            
            // Case 1: Uncle is red
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                z = grandparent;
            } else {
                // Case 2: z is right child
                if (z == parent->right) {
                    leftRotate(root, parent);
                    z = parent;
                    parent = z->parent;
                }
                // Case 3: z is left child
                rightRotate(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                z = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            
            // Case 1: Uncle is red
            if (uncle != NULL && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                z = grandparent;
            } else {
                // Case 2: z is left child
                if (z == parent->left) {
                    rightRotate(root, parent);
                    z = parent;
                    parent = z->parent;
                }
                // Case 3: z is right child
                leftRotate(root, grandparent);
                int temp = parent->color;
                parent->color = grandparent->color;
                grandparent->color = temp;
                z = parent;
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(Node **root, int key) {
    Node *z = createNode(key);
    Node *y = NULL;
    Node *x = *root;
    
    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else if (z->key > x->key)
            x = x->right;
        else {
            free(z); // Duplicate key, don't insert
            return;
        }
    }
    
    z->parent = y;
    
    if (y == NULL)
        *root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
    
    fixViolation(root, z);
}

int search(Node *root, int key) {
    while (root != NULL) {
        if (key == root->key)
            return 1;
        else if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return 0;
}

void inorderHelper(Node *root, int *first) {
    if (root != NULL) {
        inorderHelper(root->left, first);
        if (!(*first)) printf(" ");
        printf("%d(%c)", root->key, root->color == RED ? 'R' : 'B');
        *first = 0;
        inorderHelper(root->right, first);
    }
}

void inorder(Node *root) {
    if (root == NULL) {
        printf("Empty tree\n");
    } else {
        int first = 1;
        inorderHelper(root, &first);
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    
    Node *root = NULL;
    
    for (int i = 0; i < n; i++) {
        char operation[10];
        scanf("%s", operation);
        
        if (strcmp(operation, "insert") == 0) {
            int key;
            scanf("%d", &key);
            insert(&root, key);
        } else if (strcmp(operation, "search") == 0) {
            int key;
            scanf("%d", &key);
            printf("%s\n", search(root, key) ? "Found" : "Not found");
        } else if (strcmp(operation, "inorder") == 0) {
            inorder(root);
        }
    }
    
    return 0;
}
