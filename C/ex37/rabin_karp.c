/**
 * Exercise 37: Rabin-Karp String Matching (Rolling Hash)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Rabin-Karp algorithm for pattern matching using rolling hash.
 * Use polynomial rolling hash to find all occurrences of a pattern in text.
 * 
 * Input:
 * - First line: text string
 * - Second line: pattern string
 * 
 * Output:
 * - Print all starting indices where pattern is found in text
 * - If pattern not found, print "Pattern not found"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BASE 256
#define MOD 1000000007

// TODO: Implement rolling hash function

// TODO: Implement Rabin-Karp search algorithm

int main() {
    char text[100000];
    char pattern[10000];
    
    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);
    
    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;
    
    // TODO: Run Rabin-Karp algorithm
    
    // TODO: Print results
    
    return 0;
}
