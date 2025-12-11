/**
 * Exercise 40: Cartesian Tree
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Cartesian Tree for RMQ queries.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

struct CartNode {
    int value;
    int index;
    CartNode* left;
    CartNode* right;
    CartNode* parent;
    
    CartNode(int v, int idx) 
        : value(v), index(idx), left(nullptr), right(nullptr), parent(nullptr) {}
};

class CartesianTree {
private:
    CartNode* root;
    
    int rangeMin(CartNode* node, int l, int r) {
        if (!node) {
            return INT_MAX;
        }
        
        int nodeIdx = node->index;
        int result = INT_MAX;
        
        // If node is in range, include its value
        if (nodeIdx >= l && nodeIdx <= r) {
            result = node->value;
        }
        
        // Search in left subtree
        if (l <= nodeIdx) {
            int leftMin = rangeMin(node->left, l, r);
            if (leftMin < result) {
                result = leftMin;
            }
        }
        
        // Search in right subtree
        if (r >= nodeIdx) {
            int rightMin = rangeMin(node->right, l, r);
            if (rightMin < result) {
                result = rightMin;
            }
        }
        
        return result;
    }
    
    void inorderHelper(CartNode* node, bool& first) {
        if (!node) {
            return;
        }
        
        inorderHelper(node->left, first);
        
        if (!first) {
            cout << " ";
        }
        cout << node->value;
        first = false;
        
        inorderHelper(node->right, first);
    }
    
    void freeTree(CartNode* node) {
        if (!node) {
            return;
        }
        
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }
    
public:
    CartesianTree(vector<int>& arr) {
        int n = arr.size();
        
        if (n == 0) {
            root = nullptr;
            return;
        }
        
        stack<CartNode*> st;
        
        for (int i = 0; i < n; i++) {
            CartNode* node = new CartNode(arr[i], i);
            CartNode* last = nullptr;
            
            // Pop all elements greater than current element
            while (!st.empty() && st.top()->value > node->value) {
                last = st.top();
                st.pop();
            }
            
            // Attach popped node as left child of current
            if (last) {
                node->left = last;
                last->parent = node;
            }
            
            // Attach current node as right child of top element
            if (!st.empty()) {
                st.top()->right = node;
                node->parent = st.top();
            }
            
            st.push(node);
        }
        
        // Root is at bottom of stack
        while (st.size() > 1) {
            st.pop();
        }
        root = st.empty() ? nullptr : st.top();
    }
    
    int queryMin(int l, int r) {
        return rangeMin(root, l, r);
    }
    
    void inorder() {
        if (!root) {
            cout << "Empty tree" << endl;
        } else {
            bool first = true;
            inorderHelper(root, first);
            cout << endl;
        }
    }
    
    ~CartesianTree() {
        freeTree(root);
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    CartesianTree tree(arr);
    
    int q;
    cin >> q;
    cin.ignore();
    
    for (int i = 0; i < q; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "min") {
            int l, r;
            cin >> l >> r;
            cout << tree.queryMin(l, r) << endl;
        } else if (operation == "inorder") {
            tree.inorder();
        }
    }
    
    return 0;
}
