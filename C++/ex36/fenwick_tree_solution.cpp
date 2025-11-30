/**
 * Exercise 36: Fenwick Tree (Binary Indexed Tree)
 * Difficulty: ***** (5/5)
 * 
 * Solution implementing Fenwick Tree for efficient range queries and updates.
 */

#include <iostream>
#include <vector>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;
    
    int LSB(int index) {
        return index & -index;
    }
    
    void updateHelper(int index, int delta) {
        while (index <= n) {
            tree[index] += delta;
            index += LSB(index);
        }
    }
    
    int queryHelper(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= LSB(index);
        }
        return sum;
    }
    
public:
    FenwickTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(n + 1, 0);
        
        // Build tree from array
        for (int i = 0; i < n; i++) {
            updateHelper(i + 1, arr[i]);
        }
    }
    
    void update(int index, int value) {
        updateHelper(index, value);
    }
    
    int query(int index) {
        return queryHelper(index);
    }
    
    int rangeQuery(int left, int right) {
        if (left > 1) {
            return queryHelper(right) - queryHelper(left - 1);
        }
        return queryHelper(right);
    }
};

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    FenwickTree ft(arr);
    
    int q;
    cin >> q;
    cin.ignore();
    
    for (int i = 0; i < q; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "update") {
            int index, value;
            cin >> index >> value;
            ft.update(index, value);
        } else if (operation == "query") {
            int index;
            cin >> index;
            cout << ft.query(index) << endl;
        } else if (operation == "range") {
            int left, right;
            cin >> left >> right;
            cout << ft.rangeQuery(left, right) << endl;
        }
    }
    
    return 0;
}
