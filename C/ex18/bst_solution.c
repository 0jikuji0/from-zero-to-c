// Binary Search Tree - Insert and Search (Exercise 18) - Solution
// Build a binary search tree (BST) and perform search operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* create_node(int value) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node *root, int value) {
    if (root == NULL) {
        return create_node(value);
    }
    
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

int search(Node *root, int value) {
    if (root == NULL) {
        return 0;
    }
    
    if (value == root->value) {
        return 1;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void delete_tree(Node *root) {
    if (root == NULL) {
        return;
    }
    
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

int main() {
    Node *root = NULL;
    char command[50];
    int value;
    
    while (1) {
        if (scanf("%s", command) != 1) {
            break;
        }
        
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "insert") == 0) {
            if (scanf("%d", &value) == 1) {
                root = insert(root, value);
            }
        } else if (strcmp(command, "search") == 0) {
            if (scanf("%d", &value) == 1) {
                if (search(root, value)) {
                    printf("found\n");
                } else {
                    printf("not found\n");
                }
            }
        }
    }
    
    delete_tree(root);
    
    return 0;
}
