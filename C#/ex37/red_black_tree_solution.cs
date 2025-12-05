/**
 * Exercise 37: Red-Black Tree
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Red-Black Tree with insertions and rebalancing.
 */

using System;
using System.Text;

enum Color { Red, Black }

class Node
{
    public int Key { get; set; }
    public Color Color { get; set; }
    public Node Left { get; set; }
    public Node Right { get; set; }
    public Node Parent { get; set; }

    public Node(int key)
    {
        Key = key;
        Color = Color.Red;
        Left = null;
        Right = null;
        Parent = null;
    }
}

class RedBlackTree
{
    private Node root;

    public RedBlackTree()
    {
        root = null;
    }

    private void LeftRotate(Node x)
    {
        Node y = x.Right;
        x.Right = y.Left;

        if (y.Left != null)
            y.Left.Parent = x;

        y.Parent = x.Parent;

        if (x.Parent == null)
            root = y;
        else if (x == x.Parent.Left)
            x.Parent.Left = y;
        else
            x.Parent.Right = y;

        y.Left = x;
        x.Parent = y;
    }

    private void RightRotate(Node y)
    {
        Node x = y.Left;
        y.Left = x.Right;

        if (x.Right != null)
            x.Right.Parent = y;

        x.Parent = y.Parent;

        if (y.Parent == null)
            root = x;
        else if (y == y.Parent.Left)
            y.Parent.Left = x;
        else
            y.Parent.Right = x;

        x.Right = y;
        y.Parent = x;
    }

    private void FixViolation(Node z)
    {
        while (z != root && z.Parent.Color == Color.Red)
        {
            Node parent = z.Parent;
            Node grandparent = parent.Parent;

            if (parent == grandparent.Left)
            {
                Node uncle = grandparent.Right;

                // Case 1: Uncle is red
                if (uncle != null && uncle.Color == Color.Red)
                {
                    grandparent.Color = Color.Red;
                    parent.Color = Color.Black;
                    uncle.Color = Color.Black;
                    z = grandparent;
                }
                else
                {
                    // Case 2: z is right child
                    if (z == parent.Right)
                    {
                        LeftRotate(parent);
                        z = parent;
                        parent = z.Parent;
                    }
                    // Case 3: z is left child
                    RightRotate(grandparent);
                    Color temp = parent.Color;
                    parent.Color = grandparent.Color;
                    grandparent.Color = temp;
                    z = parent;
                }
            }
            else
            {
                Node uncle = grandparent.Left;

                // Case 1: Uncle is red
                if (uncle != null && uncle.Color == Color.Red)
                {
                    grandparent.Color = Color.Red;
                    parent.Color = Color.Black;
                    uncle.Color = Color.Black;
                    z = grandparent;
                }
                else
                {
                    // Case 2: z is left child
                    if (z == parent.Left)
                    {
                        RightRotate(parent);
                        z = parent;
                        parent = z.Parent;
                    }
                    // Case 3: z is right child
                    LeftRotate(grandparent);
                    Color temp = parent.Color;
                    parent.Color = grandparent.Color;
                    grandparent.Color = temp;
                    z = parent;
                }
            }
        }
        root.Color = Color.Black;
    }

    public void Insert(int key)
    {
        Node z = new Node(key);
        Node y = null;
        Node x = root;

        while (x != null)
        {
            y = x;
            if (z.Key < x.Key)
                x = x.Left;
            else if (z.Key > x.Key)
                x = x.Right;
            else
                return; // Duplicate key
        }

        z.Parent = y;

        if (y == null)
            root = z;
        else if (z.Key < y.Key)
            y.Left = z;
        else
            y.Right = z;

        FixViolation(z);
    }

    public bool Search(int key)
    {
        Node node = root;
        while (node != null)
        {
            if (key == node.Key)
                return true;
            else if (key < node.Key)
                node = node.Left;
            else
                node = node.Right;
        }
        return false;
    }

    private void InorderHelper(Node node, StringBuilder sb, ref bool first)
    {
        if (node != null)
        {
            InorderHelper(node.Left, sb, ref first);
            if (!first) sb.Append(" ");
            sb.Append($"{node.Key}({(node.Color == Color.Red ? "R" : "B")})");
            first = false;
            InorderHelper(node.Right, sb, ref first);
        }
    }

    public void Inorder()
    {
        if (root == null)
        {
            Console.WriteLine("Empty tree");
        }
        else
        {
            StringBuilder sb = new StringBuilder();
            bool first = true;
            InorderHelper(root, sb, ref first);
            Console.WriteLine(sb.ToString());
        }
    }
}

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());
        RedBlackTree tree = new RedBlackTree();

        for (int i = 0; i < n; i++)
        {
            string[] input = Console.ReadLine().Split();
            string operation = input[0];

            if (operation == "insert")
            {
                int key = int.Parse(input[1]);
                tree.Insert(key);
            }
            else if (operation == "search")
            {
                int key = int.Parse(input[1]);
                Console.WriteLine(tree.Search(key) ? "Found" : "Not found");
            }
            else if (operation == "inorder")
            {
                tree.Inorder();
            }
        }
    }
}
