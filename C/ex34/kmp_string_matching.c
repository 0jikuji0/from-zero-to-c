/**
 * Exercise 34: Knuth-Morris-Pratt (KMP) String Matching
 * Difficulty: ***** (5/5)
 * 
 * Implement the KMP algorithm for efficient pattern matching in a text.
 * Build the LPS (Longest Proper Prefix which is also Suffix) array and use it
 * to find all occurrences of a pattern in text in O(n+m) time.
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

// TODO: Implement LPS array computation

// TODO: Implement KMP search algorithm

int main() {
    char text[100000];
    char pattern[10000];
    
    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);
    
    // Remove newline characters
    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;
    
    // TODO: Run KMP algorithm
    
    // TODO: Print results
    
    return 0;
}
