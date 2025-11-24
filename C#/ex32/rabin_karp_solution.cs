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

using System;
using System.Collections.Generic;

class Program {
    const long BASE = 256;
    const long MOD = 1000000007;
    
    static long ComputeHash(string str, int len) {
        long hash = 0;
        long base_pow = 1;
        
        for (int i = 0; i < len; i++) {
            hash = (hash + ((long)str[i] * base_pow) % MOD) % MOD;
            base_pow = (base_pow * BASE) % MOD;
        }
        
        return hash;
    }
    
    static void RabinKarp(string text, string pattern) {
        int n = text.Length;
        int m = pattern.Length;
        
        if (m > n) {
            Console.WriteLine("Pattern not found");
            return;
        }
        
        long pattern_hash = ComputeHash(pattern, m);
        long text_hash = ComputeHash(text, m);
        
        long base_pow = 1;
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
                    Console.WriteLine($"Pattern found at index {i}");
                    found = true;
                }
            }
            
            if (i < n - m) {
                text_hash = (text_hash - ((long)text[i]) % MOD + MOD) % MOD;
                text_hash = (text_hash * BASE) % MOD;
                text_hash = (text_hash + ((long)text[i + m] * base_pow) % MOD) % MOD;
            }
        }
        
        if (!found) {
            Console.WriteLine("Pattern not found");
        }
    }
    
    static void Main() {
        string text = Console.ReadLine();
        string pattern = Console.ReadLine();
        
        RabinKarp(text, pattern);
    }
}
