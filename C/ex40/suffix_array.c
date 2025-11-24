/**
 * Exercise 40: Suffix Array and LCP Array (Advanced String Processing)
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 100005

// TODO: Define suffix structure with index and rank

// TODO: Implement comparison function for suffix sorting

// TODO: Implement suffix array construction using radix sort or quicksort
//       with optimization for equal prefixes

// TODO: Implement LCP array construction using Kasai's algorithm

// TODO: Implement longest repeated substring using LCP array

// TODO: Implement distinct substrings count using suffix array
//       Formula: n*(n+1)/2 - sum(LCP)

// TODO: Implement longest common substring for two strings
//       Concatenate with separator and use suffix array + LCP

int main() {
    char operation[10];
    scanf("%s", operation);
    getchar();
    
    if (strcmp(operation, "lrs") == 0) {
        // TODO: Read string and find longest repeated substring
    } else if (strcmp(operation, "count") == 0) {
        // TODO: Read string and count distinct substrings
    } else if (strcmp(operation, "lcs") == 0) {
        // TODO: Read two strings and find longest common substring
    }
    
    return 0;
}
