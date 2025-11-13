// Binary Search (Exercise 7) - Solution
// Iterative binary search returning any index of x or -1 if not found.

#include <bits/stdc++.h>
using namespace std;

int binary_search_idx(const vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
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
