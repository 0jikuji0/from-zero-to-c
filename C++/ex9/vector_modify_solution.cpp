// Vector Modify (Exercise 9) - Solution
// Demonstrates returning references from functions to modify container elements.

#include <bits/stdc++.h>
using namespace std;

int& getElement(vector<int>& vec, int idx) {
    return vec[idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> vec(n);
    for (int j = 0; j < n; ++j) cin >> vec[j];

    int i, v;
    if (!(cin >> i >> v)) return 0;

    if (i >= 0 && i < n) {
        getElement(vec, i) = v;
    }

    for (int j = 0; j < n; ++j) {
        cout << vec[j] << (j+1==n ? '\n' : ' ');
    }

    return 0;
}
