// Binary Search Tree - Insert and Search (Exercise 17) - Solution
// Build a binary search tree (BST) and perform search operations.

using System;

class Node {
    public int Value { get; set; }
    public Node? Left { get; set; }
    public Node? Right { get; set; }
    
    public Node(int value) {
        Value = value;
        Left = null;
        Right = null;
    }
}

class BST {
    private Node? root;
    
    public BST() {
        root = null;
    }
    
    public void Insert(int value) {
        if (root == null) {
            root = new Node(value);
        } else {
            InsertRecursive(root, value);
        }
    }
    
    private void InsertRecursive(Node node, int value) {
        if (value < node.Value) {
            if (node.Left == null) {
                node.Left = new Node(value);
            } else {
                InsertRecursive(node.Left, value);
            }
        } else if (value > node.Value) {
            if (node.Right == null) {
                node.Right = new Node(value);
            } else {
                InsertRecursive(node.Right, value);
            }
        }
    }
    
    public bool Search(int value) {
        return SearchRecursive(root, value);
    }
    
    private bool SearchRecursive(Node? node, int value) {
        if (node == null) {
            return false;
        }
        
        if (value == node.Value) {
            return true;
        } else if (value < node.Value) {
            return SearchRecursive(node.Left, value);
        } else {
            return SearchRecursive(node.Right, value);
        }
    }
}

class Program {
    static void Main() {
        BST bst = new BST();
        
        while (true) {
            string? line = Console.ReadLine();
            if (line == null) break;
            
            var parts = line.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
            if (parts.Length == 0) continue;
            
            string command = parts[0];
            
            if (command == "exit") {
                break;
            } else if (command == "insert" && parts.Length >= 2) {
                if (int.TryParse(parts[1], out int value)) {
                    bst.Insert(value);
                }
            } else if (command == "search" && parts.Length >= 2) {
                if (int.TryParse(parts[1], out int value)) {
                    if (bst.Search(value)) {
                        Console.WriteLine("found");
                    } else {
                        Console.WriteLine("not found");
                    }
                }
            }
        }
    }
}
