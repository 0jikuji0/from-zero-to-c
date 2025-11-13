// Exercise 8 — Pointer Arithmetic
// Difficulty: * (1/5)
//
// Problem: read n integers into a vector, then read an index i and print
// the element at index i using pointer arithmetic (not direct indexing).
//
// Input:
// n i
// a0 a1 ... a_{n-1}
//
// Output:
// a[i]  (accessed via pointer)
//
// Hints / TODOs:
// - TODO 1: read n and i from input.
// - TODO 2: read n integers into a vector.
// - TODO 3: use pointer arithmetic (vec.data() + i) to access element at index i.
// - TODO 4: print the element.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i;
    // TODO 1: read n and i
    if (!(cin >> n >> i)) return 0;

    vector<int> vec;
    // TODO 2: read n integers into vec

    // TODO 3: use pointer arithmetic to access vec[i]
    // int *ptr = vec.data() + i;
    // TODO 4: print the element using the pointer

    return 0;
}
