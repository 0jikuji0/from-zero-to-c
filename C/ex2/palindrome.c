/*
 * Palindrome (Exercise 2)
 * Difficulty: ** (2 stars) - Quite easy
 *
 * Task: implement `is_palindrome` which checks whether a given string is a palindrome.
 * The skeleton reads a single word (no spaces) and prints 1 if palindrome, 0 otherwise.
 */

#include <stdio.h>
#include <string.h>

/* TODOs: students should implement is_palindrome and minimal I/O handling.
 * Hints / steps:
 *  1) Implement `int is_palindrome(const char *s)` using a two-pointer method.
 *     - Use one index at the start (i) and one at the end (j).
 *     - Compare characters and advance i, decrement j until i >= j.
 *     - Return 1 if all matched, otherwise return 0.
 *  2) In `main`, read a single word (no spaces) into a buffer and call the function.
 */

/* TODO 1: implement this function. Return 1 if s is a palindrome, 0 otherwise. */
int is_palindrome(const char *s) {
    /* Steps to implement:
     * - find length using strlen
     * - set i = 0, j = len - 1
     * - while (i < j) { if (s[i] != s[j]) return 0; i++; j--; }
     * - return 1;
     */
    (void)s; /* placeholder */
    return /* TODO: return 1 or 0 based on check */ 0;
}

int main(void) {
    /* TODO 2: read a single word into buf (use scanf "%1023s") and check return value */
    char buf[1024];

    /* TODO 3: call is_palindrome(buf) and print 1 or 0 followed by a newline */
    return 0;
}
