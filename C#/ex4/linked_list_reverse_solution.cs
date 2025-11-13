// Solution Ex 4 — Reverse a singly linked list
using System;
using System.Collections.Generic;

class Node {
    public int val;
    public Node? next;
    public Node(int v) { val = v; next = null; }
}

class Program {
    static Node? ReadList(int n) {
        Node? head = null, tail = null;
        int read = 0;
        while (read < n) {
            string? line = Console.ReadLine();
            if (line == null) break;
            var parts = line.Split(new[]{' ','\t'}, StringSplitOptions.RemoveEmptyEntries);
            foreach (var p in parts) {
                if (read >= n) break;
                int v = int.Parse(p);
                var node = new Node(v);
                if (head == null) head = tail = node;
                else { tail!.next = node; tail = node; }
                read++;
            }
        }
        return head;
    }

    static Node? Reverse(Node? head) {
        Node? prev = null;
        var cur = head;
        while (cur != null) {
            var nx = cur.next;
            cur.next = prev;
            prev = cur;
            cur = nx;
        }
        return prev;
    }

    static void Main() {
        string? line = Console.ReadLine();
        if (line == null) return;
        int n = int.Parse(line.Trim());
        var head = ReadList(n);
        head = Reverse(head);
        var outList = new List<int>();
        while (head != null) { outList.Add(head.val); head = head.next; }
        Console.WriteLine(string.Join(' ', outList));
    }
}
