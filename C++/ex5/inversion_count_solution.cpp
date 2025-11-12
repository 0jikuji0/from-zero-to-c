/*
 * Inversion Count (C++ - Exercise 5) - Solution
 * Difficulty: ***** (5 stars) - Very hard
 */

#include <iostream>
#include <vector>

static long long merge_count(std::vector<int> &a, std::vector<int> &tmp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv = 0;
    while (i < mid && j <= right) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            inv += (mid - i);
        }
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j <= right) tmp[k++] = a[j++];
    for (int p = left; p <= right; ++p) a[p] = tmp[p];
    return inv;
}

static long long sort_count(std::vector<int> &a, std::vector<int> &tmp, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long inv = 0;
    inv += sort_count(a, tmp, left, mid);
    inv += sort_count(a, tmp, mid+1, right);
    inv += merge_count(a, tmp, left, mid+1, right);
    return inv;
}

long long count_inversions(std::vector<int> &a) {
    int n = (int)a.size();
    if (n <= 1) return 0;
    std::vector<int> tmp(n);
    return sort_count(a, tmp, 0, n-1);
}

int main() {
    int n;
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Error: expected non-negative integer n\n";
        return 1;
    }
    if (n > 100000) {
        std::cerr << "Error: n too large (max 100000)\n";
        return 1;
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> a[i])) {
            std::cerr << "Error: expected " << n << " integers\n";
            return 1;
        }
    }
    std::cout << count_inversions(a) << '\n';
    return 0;
}
/*
 * Inversion Count (C++ - Exercise 5) - Solution
 * Difficulty: ***** (5 stars) - Very hard
 */

#include <iostream>
#include <vector>

static long long merge_count(std::vector<int> &a, std::vector<int> &tmp, int left, int mid, int right) {
    int i = left, j = mid, k = left;
    long long inv = 0;
    while (i < mid && j <= right) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else {
            tmp[k++] = a[j++];
            inv += (mid - i);
        }
    }
    while (i < mid) tmp[k++] = a[i++];
    while (j <= right) tmp[k++] = a[j++];
    for (int p = left; p <= right; ++p) a[p] = tmp[p];
    return inv;
}

static long long sort_count(std::vector<int> &a, std::vector<int> &tmp, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long inv = 0;
    inv += sort_count(a, tmp, left, mid);
    inv += sort_count(a, tmp, mid+1, right);
    inv += merge_count(a, tmp, left, mid+1, right);
    return inv;
}

long long count_inversions(std::vector<int> &a) {
    int n = (int)a.size();
    if (n <= 1) return 0;
    std::vector<int> tmp(n);
    return sort_count(a, tmp, 0, n-1);
}

int main() {
    int n;
    if (!(std::cin >> n) || n < 0) {
        std::cerr << "Error: expected non-negative integer n\n";
        return 1;
    }
    if (n > 100000) {
        std::cerr << "Error: n too large (max 100000)\n";
        return 1;
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> a[i])) {
            std::cerr << "Error: expected " << n << " integers\n";
            return 1;
        }
    }
    std::cout << count_inversions(a) << '\n';
    return 0;
}
