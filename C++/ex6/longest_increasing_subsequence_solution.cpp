// Solution for the LIS exercise (O(n log n))
// Uses the "tails" technique: for each possible length, keep the smallest
// ending value of an increasing subsequence of that length.

#include <bits/stdc++.h>
using namespace std;

int lis_length(const vector<int>& a) {
    if (a.empty()) return 0;
    vector<int> tails; // tails[len-1] = minimum ending value of an increasing subsequence of length len
    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return (int)tails.size();
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
