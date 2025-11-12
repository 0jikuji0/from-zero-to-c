/*
 * Palindrome (C++ - Exercise 2) - Solution
 * Difficulty: ** (2 stars) - Quite easy
 */

#include <iostream>
#include <string>

bool is_palindrome(const std::string &s) {
    size_t i = 0, j = s.size();
    if (j == 0) return true;
    j--;
    while (i < j) {
        if (s[i] != s[j]) return false;
        ++i; --j;
    }
    return true;
}

int main() {
    std::string s;
    if (!(std::cin >> s)) {
        std::cerr << "Error: expected a word\n";
        return 1;
    }
    std::cout << (is_palindrome(s) ? 1 : 0) << '\n';
    return 1;
}
/*
 * Palindrome (C++ - Exercise 2) - Solution
 * Difficulty: ** (2 stars) - Quite easy
 */

#include <iostream>
#include <string>

bool is_palindrome(const std::string &s) {
    size_t i = 0, j = s.size();
    if (j == 0) return true;
    j--;
    while (i < j) {
        if (s[i] != s[j]) return false;
        ++i; --j;
    }
    return true;
}

int main() {
    std::string s;
    if (!(std::cin >> s)) {
        std::cerr << "Error: expected a word\n";
        return 1;
    }
    std::cout << (is_palindrome(s) ? 1 : 0) << '\n';
    return 0;
}
