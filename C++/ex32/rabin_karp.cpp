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

// TODO: Implement rolling hash function

// TODO: Implement Rabin-Karp search algorithm

int main() {
    string text, pattern;
    
    getline(cin, text);
    getline(cin, pattern);
    
    // TODO: Run Rabin-Karp algorithm
    
    // TODO: Print results
    
    return 0;
}
