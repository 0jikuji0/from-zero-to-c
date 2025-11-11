/*
 * Palindrome (Exercise 2) - Solution
 * Difficulty: ** (2 stars) - Quite easy
 *
 * Solution: simple two-pointer palindrome check.
 */

#include <stdio.h>
#include <string.h>

int is_palindrome(const char *s) {
    size_t i = 0, j = strlen(s);
    if (j == 0) return 1;
    j--; // index of last character
    while (i < j) {
        if (s[i] != s[j]) return 0;
        i++; j--;
    }
    return 1;
}

int main(void) {
    char buf[1024];
    if (scanf("%1023s", buf) != 1) {
        fprintf(stderr, "Error: expected a word\n");
        return 1;
    }
    printf("%d\n", is_palindrome(buf));
    return 0;
}
