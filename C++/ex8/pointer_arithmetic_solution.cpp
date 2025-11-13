// Pointer Arithmetic (Exercise 8) - Solution
// Demonstrates accessing vector elements via pointer arithmetic.

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i;
    if (!(cin >> n >> i)) return 0;

    vector<int> vec(n);
    for (int j = 0; j < n; ++j) cin >> vec[j];

    if (i >= 0 && i < n) {
        int *ptr = vec.data() + i;
        cout << *ptr << '\n';
    }

    return 0;
}
