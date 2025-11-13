// Exercice 4 — Reverse a singly linked list
// Niveau: Moyen
//
// Énoncé : lire n suivi de n entiers, construire une liste chaînée et
// inverser la liste (en manipulant les pointeurs). Afficher les valeurs
// de la liste inversée.

using System;

class Node {
    public int val;
    public Node? next;
    public Node(int v) { val = v; next = null; }
}

class Program {
    static Node? ReadList(int n) {
        // TODO: construire la liste chaînée
        return null;
    }

    static Node? Reverse(Node? head) {
        // TODO: inverser la liste chaînée
        return head;
    }

    static void Main() {
        // TODO: lecture, appel Reverse, impression
    }
}
