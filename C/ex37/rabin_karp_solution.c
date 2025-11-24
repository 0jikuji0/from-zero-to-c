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

long long computeHash(const char* str, int len) {
    long long hash = 0;
    long long base_pow = 1;
    
    for (int i = 0; i < len; i++) {
        hash = (hash + ((long long)str[i] * base_pow) % MOD) % MOD;
        base_pow = (base_pow * BASE) % MOD;
    }
    
    return hash;
}

void rabinKarp(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    if (m > n) {
        printf("Pattern not found\n");
        return;
    }
    
    long long pattern_hash = computeHash(pattern, m);
    long long text_hash = computeHash(text, m);
    
    long long base_pow = 1;
    for (int i = 0; i < m - 1; i++) {
        base_pow = (base_pow * BASE) % MOD;
    }
    
    int found = 0;
    
    for (int i = 0; i <= n - m; i++) {
        if (text_hash == pattern_hash) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            
            if (match) {
                printf("Pattern found at index %d\n", i);
                found = 1;
            }
        }
        
        if (i < n - m) {
            text_hash = (text_hash - ((long long)text[i]) % MOD + MOD) % MOD;
            text_hash = (text_hash * BASE) % MOD;
            text_hash = (text_hash + ((long long)text[i + m] * base_pow) % MOD) % MOD;
        }
    }
    
    if (!found) {
        printf("Pattern not found\n");
    }
}

int main() {
    char text[100000];
    char pattern[10000];
    
    fgets(text, sizeof(text), stdin);
    fgets(pattern, sizeof(pattern), stdin);
    
    text[strcspn(text, "\n")] = 0;
    pattern[strcspn(pattern, "\n")] = 0;
    
    rabinKarp(text, pattern);
    
    return 0;
}
