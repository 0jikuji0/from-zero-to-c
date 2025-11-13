/*
 * Linked List Reverse (C++ - Exercise 4) - Solution
 * Difficulty: ** (2/5)
 */

#include <iostream>

struct Node {
    int value;
    Node *next;
    Node(int v): value(v), next(nullptr) {}
};

Node* append(Node *head, int value) {
    Node *n = new Node(value);
    if (!head) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

Node* reverse_list(Node *head) {
    Node *prev = nullptr;
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
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Error: expected non-negative integer n\n";
        return 1;
    }
    Node *head = nullptr;
    for (int i = 0; i < n; ++i) {
        int v;
        if (!(std::cin >> v)) {
            std::cerr << "Error: expected " << n << " integers\n";
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
/*
 * Linked List Reverse (C++ - Exercise 4) - Solution
 * Difficulty: ** (2/5)
 */

#include <iostream>

struct Node {
    int value;
    Node *next;
    Node(int v): value(v), next(nullptr) {}
};

Node* append(Node *head, int value) {
    Node *n = new Node(value);
    if (!head) return n;
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

Node* reverse_list(Node *head) {
    Node *prev = nullptr;
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
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Error: expected non-negative integer n\n";
        return 1;
    }
    Node *head = nullptr;
    for (int i = 0; i < n; ++i) {
        int v;
        if (!(std::cin >> v)) {
            std::cerr << "Error: expected " << n << " integers\n";
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
