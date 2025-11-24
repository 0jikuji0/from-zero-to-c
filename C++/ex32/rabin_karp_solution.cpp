/**
 * Exercise 32: Rabin-Karp String Matching (Rolling Hash)
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

#include <iostream>
#include <string>

using namespace std;

const long long BASE = 256;
const long long MOD = 1000000007;

long long computeHash(const string& str, int len) {
    long long hash = 0;
    long long base_pow = 1;
    
    for (int i = 0; i < len; i++) {
        hash = (hash + ((long long)str[i] * base_pow) % MOD) % MOD;
        base_pow = (base_pow * BASE) % MOD;
    }
    
    return hash;
}

void rabinKarp(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    if (m > n) {
        cout << "Pattern not found" << endl;
        return;
    }
    
    long long pattern_hash = computeHash(pattern, m);
    long long text_hash = computeHash(text, m);
    
    long long base_pow = 1;
    for (int i = 0; i < m - 1; i++) {
        base_pow = (base_pow * BASE) % MOD;
    }
    
    bool found = false;
    
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
                cout << "Pattern found at index " << i << endl;
                found = true;
            }
        }
        
        if (i < n - m) {
            text_hash = (text_hash - ((long long)text[i]) % MOD + MOD) % MOD;
            text_hash = (text_hash * BASE) % MOD;
            text_hash = (text_hash + ((long long)text[i + m] * base_pow) % MOD) % MOD;
        }
    }
    
    if (!found) {
        cout << "Pattern not found" << endl;
    }
}

int main() {
    string text, pattern;
    
    getline(cin, text);
    getline(cin, pattern);
    
    rabinKarp(text, pattern);
    
    return 0;
}
