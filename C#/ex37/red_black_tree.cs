/**
 * Exercise 37: Red-Black Tree
 * Difficulty: ***** (5/5)
 * 
 * Implement a Red-Black Tree, a self-balancing binary search tree with the
 * following properties:
 * 1. Every node is either red or black
 * 2. Root is always black
 * 3. All leaves (null) are black
 * 4. Red nodes cannot have red children
 * 5. Every path from root to leaf has the same number of black nodes
 * 
 * Operations:
 * - Insert: Add a new key and rebalance with rotations and recoloring
 * - Search: Check if a key exists
 * - Inorder: Print inorder traversal showing colors
 * 
 * Input:
 * - First line: number of operations N
 * - Next N lines: operation commands
 *   - "insert X": insert key X
 *   - "search X": search for key X
 *   - "inorder": print inorder traversal with colors
 * 
 * Output:
 * - For "search X": print "Found" or "Not found"
 * - For "inorder": print keys with color (e.g., "5(B) 10(R) 15(B)")
 *   (or "Empty tree" if tree is empty)
 */

using System;

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

    // TODO: Implement LeftRotate(x): perform left rotation

    // TODO: Implement RightRotate(y): perform right rotation

    // TODO: Implement FixViolation(z): fix red-black violations after insertion

    // TODO: Implement Insert(key): insert and fix violations

    // TODO: Implement Search(key): search for a key

    // TODO: Implement Inorder(): print inorder traversal with colors
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

            // TODO: Handle operations based on command
        }
    }
}
