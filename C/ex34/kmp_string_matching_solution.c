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

void computeLPS(const char* pattern, int m, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    int* lps = (int*)malloc(sizeof(int) * m);
    computeLPS(pattern, m, lps);
    
    int i = 0;
    int j = 0;
    int found = 0;
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            found = 1;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    if (!found) {
        printf("Pattern not found\n");
    }
    
    free(lps);
}

int main() {
    char text[100000];
    char pattern[10000];
    
    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);
    
    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;
    
    KMPSearch(text, pattern);
    
    return 0;
}
