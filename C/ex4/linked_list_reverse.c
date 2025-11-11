/*
 * Linked List Reverse (Exercise 4)
 * Difficulty: **** (4 stars) - Hard
 *
 * Task: implement a simple singly linked list and the function `reverse_list` that
 * reverses the list in-place. The skeleton includes append and print functions.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

/* TODOs: students should implement append and reverse_list. Hints:
 *  - append: create a new node with malloc, set its value and next=NULL.
 *    If head is NULL, return the new node; otherwise traverse to the end
 *    and link the new node.
 *  - reverse_list: use three pointers (prev, cur, next). Iterate through list
 *    and reverse the links, finally return prev as the new head.
 */

/* TODO 1: implement append. Allocate a new node and attach it at the end. */
Node* append(Node *head, int value) {
    /* Steps:
     *  - allocate a Node
     *  - set node->value = value, node->next = NULL
     *  - if head == NULL return node
     *  - otherwise iterate to last node and set last->next = node
     *  - return head
     */
    (void)head; (void)value; /* placeholders */
    return NULL; /* TODO: replace with actual behavior */
}

/* TODO 2: implement reverse_list following the three-pointer method. */
Node* reverse_list(Node *head) {
    /* Steps:
     *  - Node *prev = NULL, *cur = head;
     *  - while (cur) { Node *next = cur->next; cur->next = prev; prev = cur; cur = next; }
     *  - return prev;
     */
    (void)head;
    return NULL; /* TODO: return new head */
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
