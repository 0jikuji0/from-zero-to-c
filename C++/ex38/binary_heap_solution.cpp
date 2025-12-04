/**
 * Exercise 38: Binary Min-Heap
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing a Min-Heap using vector.
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    
    int parent(int index) {
        return (index - 1) / 2;
    }
    
    int leftChild(int index) {
        return 2 * index + 1;
    }
    
    int rightChild(int index) {
        return 2 * index + 2;
    }
    
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] > heap[index]) {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }
    
    void heapifyDown(int index) {
        int minIndex = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if (left < heap.size() && heap[left] < heap[minIndex]) {
            minIndex = left;
        }
        
        if (right < heap.size() && heap[right] < heap[minIndex]) {
            minIndex = right;
        }
        
        if (index != minIndex) {
            swap(heap[index], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }
    
public:
    MinHeap() {}
    
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    
    bool extractMin(int& result) {
        if (heap.empty()) {
            return false;
        }
        
        result = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return true;
    }
    
    bool peek(int& result) {
        if (heap.empty()) {
            return false;
        }
        
        result = heap[0];
        return true;
    }
    
    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    MinHeap heap;
    
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "insert") {
            int value;
            cin >> value;
            heap.insert(value);
        } else if (operation == "extract") {
            int result;
            if (heap.extractMin(result)) {
                cout << result << endl;
            } else {
                cout << "Heap is empty" << endl;
            }
        } else if (operation == "peek") {
            int result;
            if (heap.peek(result)) {
                cout << result << endl;
            } else {
                cout << "Heap is empty" << endl;
            }
        } else if (operation == "empty") {
            cout << (heap.isEmpty() ? "true" : "false") << endl;
        }
    }
    
    return 0;
}
