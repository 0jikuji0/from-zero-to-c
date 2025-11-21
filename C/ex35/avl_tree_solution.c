/**
 * Exercise 35: AVL Tree (Self-Balancing Binary Search Tree)
 * Difficulty: ***** (5/5)
 * 
 * Implement an AVL tree with insertion, deletion, and search operations.
 * Maintain balance using rotations after each insertion/deletion.
 * 
 * Input:
 * - First line: number of operations (q)
 * - Next q lines: operations in format:
 *   - "insert value" - insert value into AVL tree
 *   - "delete value" - delete value from AVL tree
 *   - "search value" - check if value exists
 *   - "inorder" - print inorder traversal
 * 
 * Output:
 * - For search operations: print "found" or "not found"
 * - For inorder operation: print all values in sorted order
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

Node* insert(Node* node, int value) {
    if (!node) {
        return createNode(value);
    }
    
    if (value < node->value) {
        node->left = insert(node->left, value);
    } else if (value > node->value) {
        node->right = insert(node->right, value);
    } else {
        return node;
    }
    
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    if (balance > 1 && value < node->left->value) {
        return rightRotate(node);
    }
    
    if (balance < -1 && value > node->right->value) {
        return leftRotate(node);
    }
    
    if (balance > 1 && value > node->left->value) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if (balance < -1 && value < node->right->value) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int value) {
    if (!root) {
        return root;
    }
    
    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            
            if (!temp) {
                temp = root;
                root = NULL;
            } else {
                *root = *temp;
            }
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
    }
    
    if (!root) {
        return root;
    }
    
    root->height = 1 + max(height(root->left), height(root->right));
    
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

bool search(Node* root, int value) {
    if (!root) {
        return false;
    }
    
    if (value == root->value) {
        return true;
    } else if (value < root->value) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

int main() {
    int q;
    scanf("%d", &q);
    
    Node* root = NULL;
    
    for (int i = 0; i < q; i++) {
        char operation[10];
        scanf("%s", operation);
        
        if (strcmp(operation, "insert") == 0) {
            int value;
            scanf("%d", &value);
            root = insert(root, value);
        } else if (strcmp(operation, "delete") == 0) {
            int value;
            scanf("%d", &value);
            root = deleteNode(root, value);
        } else if (strcmp(operation, "search") == 0) {
            int value;
            scanf("%d", &value);
            printf("%s\n", search(root, value) ? "found" : "not found");
        } else if (strcmp(operation, "inorder") == 0) {
            inorder(root);
            printf("\n");
        }
    }
    
    return 0;
}
