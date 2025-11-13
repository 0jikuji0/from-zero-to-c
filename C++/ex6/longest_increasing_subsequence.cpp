// Exercise 6 — Longest Increasing Subsequence (LIS)
// Difficulty: Medium
//
// Problem statement:
// Read an integer n (1 ≤ n ≤ 100000) followed by n integers, and print the
// length of the longest strictly increasing subsequence (LIS).
//
// Input format:
// n
// a1 a2 a3 ... an
//
// Output format:
// length_of_the_LIS
//
// Example:
// Input:
// 8
// 10 9 2 5 3 7 101 18
// Output:
// 4
//
// Notes:
// - Implement the function `int lis_length(const vector<int>& a)`.
// - You may use an O(n log n) algorithm or an O(n^2) algorithm.
// - Do not change the way input/output is handled in `main`.

#include <bits/stdc++.h>
using namespace std;

int lis_length(const vector<int>& a) {
    // TODO: implement the logic here
    // Return the length of the longest strictly increasing subsequence
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << lis_length(a) << '\n';
    return 0;
}

