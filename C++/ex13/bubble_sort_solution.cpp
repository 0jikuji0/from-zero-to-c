// Bubble Sort (Exercise 13) - Solution
// Sort a vector using bubble sort algorithm.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << vec[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}
