/**
 * Exercise 26: Huffman Coding (Data Compression)
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct {
    Node** heap;
    int size;
    int capacity;
} MinHeap;

MinHeap* createMinHeap(int capacity) {
    MinHeap* h = malloc(sizeof(MinHeap));
    h->heap = malloc(sizeof(Node*) * capacity);
    h->size = 0;
    h->capacity = capacity;
    return h;
}

void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(MinHeap* h, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < h->size && h->heap[left]->freq < h->heap[smallest]->freq) {
        smallest = left;
    }
    if (right < h->size && h->heap[right]->freq < h->heap[smallest]->freq) {
        smallest = right;
    }
    
    if (smallest != idx) {
        swap(&h->heap[idx], &h->heap[smallest]);
        minHeapify(h, smallest);
    }
}

void insert(MinHeap* h, Node* node) {
    if (h->size >= h->capacity) return;
    
    int idx = h->size++;
    h->heap[idx] = node;
    
    while (idx > 0 && h->heap[idx]->freq < h->heap[(idx - 1) / 2]->freq) {
        swap(&h->heap[idx], &h->heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

Node* extractMin(MinHeap* h) {
    if (h->size == 0) return NULL;
    
    Node* min = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    
    if (h->size > 0) {
        minHeapify(h, 0);
    }
    
    return min;
}

Node* createNode(char ch, int freq) {
    Node* node = malloc(sizeof(Node));
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void generateCodes(Node* root, char code[256][256], char prefix[256], int depth) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        prefix[depth] = '\0';
        strcpy(code[root->ch], prefix);
        return;
    }
    
    if (root->left) {
        prefix[depth] = '0';
        generateCodes(root->left, code, prefix, depth + 1);
    }
    
    if (root->right) {
        prefix[depth] = '1';
        generateCodes(root->right, code, prefix, depth + 1);
    }
}

int main() {
    char text[1000];
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    
    int freq[256] = {0};
    for (int i = 0; text[i]; i++) {
        freq[(unsigned char)text[i]]++;
    }
    
    MinHeap* h = createMinHeap(256);
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            insert(h, createNode(i, freq[i]));
        }
    }
    
    while (h->size > 1) {
        Node* left = extractMin(h);
        Node* right = extractMin(h);
        
        Node* parent = createNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        
        insert(h, parent);
    }
    
    Node* root = extractMin(h);
    
    char codes[256][256];
    memset(codes, 0, sizeof(codes));
    
    char prefix[256] = "";
    generateCodes(root, codes, prefix, 0);
    
    long long totalBits = 0;
    for (int i = 0; i < (int)strlen(text); i++) {
        totalBits += strlen(codes[(unsigned char)text[i]]);
    }
    
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: %d bits = %s\n", i, freq[i], codes[i]);
        }
    }
    
    printf("Total bits: %lld\n", totalBits);
    
    free(h->heap);
    free(h);
    
    return 0;
}
