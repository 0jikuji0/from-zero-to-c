/**
 * Exercise 25: Huffman Coding (Data Compression)
 * Difficulty: ***** (5/5)
 * 
 * Implement Huffman coding to compress text data.
 * Build a Huffman tree from character frequencies and generate codes.
 * 
 * Input:
 * - A string to be encoded
 * 
 * Output:
 * - Print frequency of each character
 * - Print Huffman code for each character
 * - Print total bits needed for encoding
 */

using System;
using System.Collections.Generic;
using System.Linq;

class Node {
    public char Ch { get; set; }
    public int Freq { get; set; }
    public Node Left { get; set; }
    public Node Right { get; set; }
    
    public Node(char c, int f) {
        Ch = c;
        Freq = f;
        Left = null;
        Right = null;
    }
}

class NodeComparer : IComparer<Node> {
    public int Compare(Node a, Node b) {
        return a.Freq.CompareTo(b.Freq);
    }
}

class Program {
    static void GenerateCodes(Node root, string code, Dictionary<char, string> codes) {
        if (root == null) return;
        
        if (root.Left == null && root.Right == null) {
            codes[root.Ch] = code;
            return;
        }
        
        if (root.Left != null) {
            GenerateCodes(root.Left, code + "0", codes);
        }
        
        if (root.Right != null) {
            GenerateCodes(root.Right, code + "1", codes);
        }
    }
    
    static void Main() {
        string text = Console.ReadLine();
        
        Dictionary<char, int> freq = new Dictionary<char, int>();
        foreach (char c in text) {
            if (freq.ContainsKey(c)) {
                freq[c]++;
            } else {
                freq[c] = 1;
            }
        }
        
        var pq = new SortedSet<Node>(new NodeComparer());
        
        foreach (var p in freq) {
            pq.Add(new Node(p.Key, p.Value));
        }
        
        while (pq.Count > 1) {
            Node left = pq.Min;
            pq.Remove(left);
            Node right = pq.Min;
            pq.Remove(right);
            
            Node parent = new Node('\0', left.Freq + right.Freq);
            parent.Left = left;
            parent.Right = right;
            
            pq.Add(parent);
        }
        
        Node root = pq.Min;
        
        Dictionary<char, string> codes = new Dictionary<char, string>();
        if (root.Left != null || root.Right != null) {
            GenerateCodes(root, "", codes);
        } else {
            codes[root.Ch] = "0";
        }
        
        long totalBits = 0;
        foreach (char c in text) {
            totalBits += codes[c].Length;
        }
        
        foreach (var p in freq) {
            Console.WriteLine($"{p.Key}: {p.Value} bits = {codes[p.Key]}");
        }
        
        Console.WriteLine($"Total bits: {totalBits}");
    }
}
