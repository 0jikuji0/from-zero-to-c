/**
 * Exercise 38: Binary Min-Heap
 * Difficulty: ***** (5/5)
 * 
 * Implement a Min-Heap data structure using a vector.
 * A heap is a complete binary tree where each parent node has a value less
 * than or equal to its children (heap property).
 * 
 * Operations:
 * - Insert: Add element and bubble up to maintain heap property
 * - ExtractMin: Remove and return minimum (root), then bubble down
 * - Peek: Return minimum without removing
 * - IsEmpty: Check if heap is empty
 * 
 * Use array indexing for parent-child relationships:
 * - Parent of i: (i-1)/2
 * - Left child of i: 2*i + 1
 * - Right child of i: 2*i + 2
 * 
 * Input:
 * - First line: number of operations N
 * - Next N lines: operation commands
 *   - "insert X": insert value X
 *   - "extract": extract and print minimum
 *   - "peek": print minimum without removing
 *   - "empty": print "true" or "false"
 * 
 * Output:
 * - For "extract": print minimum value (or "Heap is empty")
 * - For "peek": print minimum value (or "Heap is empty")
 * - For "empty": print "true" or "false"
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    
    // TODO: Implement parent(index): return parent index
    
    // TODO: Implement leftChild(index): return left child index
    
    // TODO: Implement rightChild(index): return right child index
    
    // TODO: Implement heapifyUp(index): bubble up to maintain heap property
    
    // TODO: Implement heapifyDown(index): bubble down to maintain heap property
    
public:
    MinHeap() {}
    
    // TODO: Implement insert(value): add element and heapify up
    
    // TODO: Implement extractMin(): remove root, replace with last, heapify down
    
    // TODO: Implement peek(): return root without removing
    
    // TODO: Implement isEmpty(): check if heap is empty
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    MinHeap heap;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        // TODO: Handle operations based on command
    }
    
    return 0;
}
