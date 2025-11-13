/*
 * Linked List Reverse (Exercise 4) - Solution
 * Difficulty: ** (2/5)
 *
 * Solution: reverse a singly linked list in-place.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* append(Node *head, int value) {
    Node *n = malloc(sizeof(Node));
    if (!n) return head;
    n->value = value;
    n->next = NULL;
    if (!head) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

Node* reverse_list(Node *head) {
    Node *prev = NULL;
    Node *cur = head;
    while (cur) {
        Node *next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void free_list(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

void print_list(Node *head) {
    for (Node *cur = head; cur; cur = cur->next) {
        printf("%d%s", cur->value, cur->next ? " " : "\n");
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 0) {
        fprintf(stderr, "Error: expected non-negative integer n\n");
        return 1;
    }
    Node *head = NULL;
    for (int i = 0; i < n; ++i) {
        int v;
        if (scanf("%d", &v) != 1) {
            fprintf(stderr, "Error: expected %d integers\n", n);
            free_list(head);
            return 1;
        }
        head = append(head, v);
    }
    head = reverse_list(head);
    print_list(head);
    free_list(head);
    return 0;
}
