/**
 * Exercise 34: Suffix Array and LCP Array (Advanced String Processing)
 * Difficulty: ****** (6/5) - BONUS CHALLENGE
 * 
 * Implement a Suffix Array construction algorithm with O(n log n) complexity
 * and compute the Longest Common Prefix (LCP) array using Kasai's algorithm.
 * Use these structures to solve various string problems:
 * - Find longest repeated substring
 * - Count distinct substrings
 * - Find longest common substring between two strings
 * 
 * This is an advanced data structure combining sorting, ranking, and efficient
 * string comparison techniques used in competitive programming and bioinformatics.
 * 
 * Input:
 * - First line: operation type ("lrs", "count", or "lcs")
 * - Second line: string S (for lrs and count)
 * - For "lcs": Second line: string S1, Third line: string S2
 * 
 * Output:
 * - For "lrs": print the longest repeated substring (or "No repeat" if none)
 * - For "count": print the number of distinct substrings
 * - For "lcs": print the longest common substring (or "No common substring")
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// TODO: Define Suffix structure with index and rank array

// TODO: Implement comparison operator for Suffix sorting

// TODO: Implement buildSuffixArray function using prefix doubling technique
//       with O(n log n) complexity

// TODO: Implement buildLCPArray function using Kasai's algorithm

// TODO: Implement longestRepeatedSubstring using LCP array

// TODO: Implement countDistinctSubstrings using suffix array
//       Formula: n*(n+1)/2 - sum(LCP)

// TODO: Implement longestCommonSubstring for two strings
//       Concatenate with separator and use suffix array + LCP

int main() {
    string operation;
    cin >> operation;
    cin.ignore();
    
    if (operation == "lrs") {
        // TODO: Read string and find longest repeated substring
    } else if (operation == "count") {
        // TODO: Read string and count distinct substrings
    } else if (operation == "lcs") {
        // TODO: Read two strings and find longest common substring
    }
    
    return 0;
}
