/*
 * Selection Sort (C++ - Exercise 3) - Solution
 * Difficulty: *** (3 stars) - Easy
 */

#include <iostream>
#include <vector>

void selection_sort(std::vector<int> &a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        if (min_idx != i) std::swap(a[i], a[min_idx]);
    }
}

int main() {
    int n;
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Error: expected a positive integer n\n";
        return 1;
    }
    if (n > 1000) {
        std::cerr << "Error: n too large (max 1000)\n";
        return 1;
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> a[i])) {
            std::cerr << "Error: expected " << n << " integers\n";
            return 1;
        }
    }
    selection_sort(a);
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i+1==n ? '\n' : ' ');
    }
    return 0;
}
/*
 * Selection Sort (C++ - Exercise 3) - Solution
 * Difficulty: *** (3 stars) - Easy
 */

#include <iostream>
#include <vector>

void selection_sort(std::vector<int> &a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        if (min_idx != i) std::swap(a[i], a[min_idx]);
    }
}

int main() {
    int n;
    if (!(std::cin >> n) || n <= 0) {
        std::cerr << "Error: expected a positive integer n\n";
        return 1;
    }
    if (n > 1000) {
        std::cerr << "Error: n too large (max 1000)\n";
        return 1;
    }
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> a[i])) {
            std::cerr << "Error: expected " << n << " integers\n";
            return 1;
        }
    }
    selection_sort(a);
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << (i+1==n ? '\n' : ' ');
    }
    return 0;
}
