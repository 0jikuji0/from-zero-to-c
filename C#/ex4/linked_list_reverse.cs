// Exercise 4 — Reverse a singly linked list
// Difficulty: ** (2/5)
//
// Problem: read n followed by n integers, build a singly linked list and
// reverse it in-place (by manipulating pointers). Print the values of the
// reversed list.

using System;

class Node {
    public int val;
    public Node? next;
    public Node(int v) { val = v; next = null; }
}

class Program {
    static Node? ReadList(int n) {
        // TODO: build the linked list from input
        return null;
    }

    static Node? Reverse(Node? head) {
        // TODO: reverse the linked list in-place
        return head;
    }

    static void Main() {
        // TODO: read input, call Reverse, print output
    }
}
