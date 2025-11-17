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

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        codes[root->ch] = code;
        return;
    }
    
    if (root->left) {
        generateCodes(root->left, code + "0", codes);
    }
    
    if (root->right) {
        generateCodes(root->right, code + "1", codes);
    }
}

int main() {
    string text;
    getline(cin, text);
    
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    for (auto& p : freq) {
        pq.push(new Node(p.first, p.second));
    }
    
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        
        pq.push(parent);
    }
    
    Node* root = pq.top();
    pq.pop();
    
    unordered_map<char, string> codes;
    if (root->left || root->right) {
        generateCodes(root, "", codes);
    } else {
        codes[root->ch] = "0";
    }
    
    long long totalBits = 0;
    for (char c : text) {
        totalBits += codes[c].length();
    }
    
    for (auto& p : freq) {
        cout << p.first << ": " << p.second << " bits = " << codes[p.first] << "\n";
    }
    
    cout << "Total bits: " << totalBits << "\n";
    
    return 0;
}
