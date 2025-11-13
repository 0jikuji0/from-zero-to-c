// Exercise 9 — Vector Element Modification via References
// Difficulty: * (1 star) - Easy
//
// Problem: read n integers into a vector, then read an index i and a value v.
// Modify vec[i] = v using a reference returned from a helper function.
// Print the modified vector.
//
// Input:
// n
// a0 a1 ... a_{n-1}
// i v
//
// Output:
// a0 a1 ... (with a[i] = v)
//
// Hints / TODOs:
// - TODO 1: implement `int& getElement(vector<int>& vec, int idx)` that returns
//   a reference to vec[idx].
// - TODO 2: read n integers into a vector.
// - TODO 3: read i and v, then use getElement to modify the vector.
// - TODO 4: print the modified vector.

#include <bits/stdc++.h>
using namespace std;

// TODO: implement int& getElement(vector<int>& vec, int idx)
// that returns a reference to vec[idx]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    // TODO 1: read n
    if (!(cin >> n)) return 0;

    vector<int> vec(n);
    // TODO 2: read n integers into vec

    int i, v;
    // TODO 3: read i and v
    if (!(cin >> i >> v)) return 0;

    // TODO 3 (continued): use getElement to modify vec[i]
    // getElement(vec, i) = v;

    // TODO 4: print the modified vector
    for (int j = 0; j < n; ++j) {
        // cout << vec[j] << (j+1==n ? '\n' : ' ');
    }

    return 0;
}
