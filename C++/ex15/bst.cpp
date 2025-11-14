#include <bits/stdc++.h>
using namespace std;

// TODO: Define the Node structure with int value and left/right pointers

class BST {
private:
    // TODO: Declare root node pointer
    
    // TODO: Implement InsertRecursive helper method
    
    // TODO: Implement SearchRecursive helper method
    
public:
    BST() {
        // TODO: Initialize root to nullptr
    }
    
    // TODO: Implement Insert method
    void Insert(int value) {
        
    }
    
    // TODO: Implement Search method
    bool Search(int value) {
        
    }
};

int main() {
    BST bst;
    string command;
    
    while (true) {
        cin >> command;
        
        if (command == "insert") {
            int value;
            cin >> value;
            bst.Insert(value);
        } else if (command == "search") {
            int value;
            cin >> value;
            if (bst.Search(value)) {
                cout << "found" << endl;
            } else {
                cout << "not found" << endl;
            }
        } else if (command == "exit") {
            break;
        }
    }
    
    return 0;
}
