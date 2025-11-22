/**
 * Exercise 31: AVL Tree (Self-Balancing Binary Search Tree)
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

using System;
using System.Collections.Generic;

class Node {
    public int Value { get; set; }
    public Node Left { get; set; }
    public Node Right { get; set; }
    public int Height { get; set; }
    
    public Node(int value) {
        Value = value;
        Left = null;
        Right = null;
        Height = 1;
    }
}

class AVLTree {
    private Node root;
    
    private int Height(Node node) {
        return node?.Height ?? 0;
    }
    
    private int GetBalance(Node node) {
        return node == null ? 0 : Height(node.Left) - Height(node.Right);
    }
    
    private Node RightRotate(Node y) {
        Node x = y.Left;
        Node T2 = x.Right;
        
        x.Right = y;
        y.Left = T2;
        
        y.Height = Math.Max(Height(y.Left), Height(y.Right)) + 1;
        x.Height = Math.Max(Height(x.Left), Height(x.Right)) + 1;
        
        return x;
    }
    
    private Node LeftRotate(Node x) {
        Node y = x.Right;
        Node T2 = y.Left;
        
        y.Left = x;
        x.Right = T2;
        
        x.Height = Math.Max(Height(x.Left), Height(x.Right)) + 1;
        y.Height = Math.Max(Height(y.Left), Height(y.Right)) + 1;
        
        return y;
    }
    
    public void Insert(int value) {
        root = InsertRec(root, value);
    }
    
    private Node InsertRec(Node node, int value) {
        if (node == null) {
            return new Node(value);
        }
        
        if (value < node.Value) {
            node.Left = InsertRec(node.Left, value);
        } else if (value > node.Value) {
            node.Right = InsertRec(node.Right, value);
        } else {
            return node;
        }
        
        node.Height = 1 + Math.Max(Height(node.Left), Height(node.Right));
        
        int balance = GetBalance(node);
        
        if (balance > 1 && value < node.Left.Value) {
            return RightRotate(node);
        }
        
        if (balance < -1 && value > node.Right.Value) {
            return LeftRotate(node);
        }
        
        if (balance > 1 && value > node.Left.Value) {
            node.Left = LeftRotate(node.Left);
            return RightRotate(node);
        }
        
        if (balance < -1 && value < node.Right.Value) {
            node.Right = RightRotate(node.Right);
            return LeftRotate(node);
        }
        
        return node;
    }
    
    private Node MinValueNode(Node node) {
        Node current = node;
        while (current.Left != null) {
            current = current.Left;
        }
        return current;
    }
    
    public void Delete(int value) {
        root = DeleteRec(root, value);
    }
    
    private Node DeleteRec(Node root, int value) {
        if (root == null) {
            return root;
        }
        
        if (value < root.Value) {
            root.Left = DeleteRec(root.Left, value);
        } else if (value > root.Value) {
            root.Right = DeleteRec(root.Right, value);
        } else {
            if (root.Left == null || root.Right == null) {
                Node temp = root.Left ?? root.Right;
                
                if (temp == null) {
                    temp = root;
                    root = null;
                } else {
                    root = temp;
                }
            } else {
                Node temp = MinValueNode(root.Right);
                root.Value = temp.Value;
                root.Right = DeleteRec(root.Right, temp.Value);
            }
        }
        
        if (root == null) {
            return root;
        }
        
        root.Height = 1 + Math.Max(Height(root.Left), Height(root.Right));
        
        int balance = GetBalance(root);
        
        if (balance > 1 && GetBalance(root.Left) >= 0) {
            return RightRotate(root);
        }
        
        if (balance > 1 && GetBalance(root.Left) < 0) {
            root.Left = LeftRotate(root.Left);
            return RightRotate(root);
        }
        
        if (balance < -1 && GetBalance(root.Right) <= 0) {
            return LeftRotate(root);
        }
        
        if (balance < -1 && GetBalance(root.Right) > 0) {
            root.Right = RightRotate(root.Right);
            return LeftRotate(root);
        }
        
        return root;
    }
    
    public bool Search(int value) {
        return SearchRec(root, value);
    }
    
    private bool SearchRec(Node root, int value) {
        if (root == null) {
            return false;
        }
        
        if (value == root.Value) {
            return true;
        } else if (value < root.Value) {
            return SearchRec(root.Left, value);
        } else {
            return SearchRec(root.Right, value);
        }
    }
    
    public void Inorder() {
        InorderRec(root);
        Console.WriteLine();
    }
    
    private void InorderRec(Node root) {
        if (root != null) {
            InorderRec(root.Left);
            Console.Write(root.Value + " ");
            InorderRec(root.Right);
        }
    }
}

class Program {
    static void Main() {
        int q = int.Parse(Console.ReadLine());
        
        AVLTree tree = new AVLTree();
        
        for (int i = 0; i < q; i++) {
            string[] parts = Console.ReadLine().Split();
            string operation = parts[0];
            
            if (operation == "insert") {
                int value = int.Parse(parts[1]);
                tree.Insert(value);
            } else if (operation == "delete") {
                int value = int.Parse(parts[1]);
                tree.Delete(value);
            } else if (operation == "search") {
                int value = int.Parse(parts[1]);
                Console.WriteLine(tree.Search(value) ? "found" : "not found");
            } else if (operation == "inorder") {
                tree.Inorder();
            }
        }
    }
}
