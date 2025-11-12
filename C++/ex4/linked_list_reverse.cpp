/*
 * Linked List Reverse (C++ - Exercise 4)
 * Difficulty: **** (4 stars) - Hard
 */

#include <iostream>

struct Node {
    int value;
    Node *next;
    Node(int v): value(v), next(nullptr) {}
};

// TODO: implement append and reverse_list following the hints in comments
Node* append(Node *head, int value) {
    // Steps:
    // - allocate new Node
    // - if head == nullptr return new node
    // - otherwise traverse to end and attach
    return nullptr; // placeholder
}

Node* reverse_list(Node *head) {
    // Steps:
    // - Node *prev = nullptr, *cur = head;
    // - while (cur) { Node *next = cur->next; cur->next = prev; prev = cur; cur = next; }
    // - return prev;
    return nullptr; // placeholder
}

void free_list(Node *head) {
    while (head) {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

void print_list(Node *head) {
    for (Node *cur = head; cur; cur = cur->next) {
        std::cout << cur->value << (cur->next ? ' ' : '\n');
    }
}

int main() {
    int n;
    // TODO: read n, read n integers, append to list, call reverse_list and print
    return 0;
}
