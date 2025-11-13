// Exercise 7 — Binary Search
// Difficulty: ** (2/5)
//
// Problem: given a sorted array of n integers and a value x, determine
// whether x exists in the array. If yes, print the 0-based index of any
// occurrence; otherwise print -1.
//
// Input:
// n x
// a0 a1 a2 ... a_{n-1}
//
// Output:
// index   (or -1 if not found)
//
// Hints / TODOs for students:
// - Implement `int binary_search(const vector<int>& a, int x)` that returns
//   the index or -1.
// - Use an iterative or recursive binary search (O(log n)).
// - Do not modify input/output format in `main`.

#include <bits/stdc++.h>
using namespace std;

int binary_search_idx(const vector<int>& a, int x) {
    // TODO: implement binary search and return the index of x or -1
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long x;
    if (!(cin >> n >> x)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << binary_search_idx(a, (int)x) << '\n';
    return 0;
}
