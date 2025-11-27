/**
 * Exercise 41: Z Algorithm for Pattern Matching
 * Difficulty: ***** (5/5)
 * 
 * Implement the Z Algorithm, which computes the Z-array for a given string.
 * Z[i] represents the length of the longest substring starting from S[i]
 * which is also a prefix of S. This algorithm is used for efficient pattern
 * matching in O(n+m) time complexity.
 * 
 * Applications:
 * - Linear time pattern matching
 * - Finding all occurrences of a pattern in a text
 * - String preprocessing for various algorithms
 * 
 * Input:
 * - First line: operation type ("build" or "search")
 * - For "build": Second line contains a string S
 * - For "search": Second line contains pattern P, Third line contains text T
 * 
 * Output:
 * - For "build": print the Z-array values (space-separated)
 * - For "search": print all starting positions where pattern occurs (0-indexed)
 *   or "No match" if pattern not found
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 100005

// TODO: Implement Z-algorithm to compute Z-array
// The Z-array is constructed in O(n) time using the Z-box concept
// Hint: Maintain left (L) and right (R) boundaries of the rightmost Z-box

// TODO: Implement pattern search using Z-algorithm
// Concatenate pattern and text with a separator: P$T
// Then compute Z-array and check where Z[i] equals pattern length

int main() {
    char operation[10];
    scanf("%s", operation);
    getchar();
    
    if (strcmp(operation, "build") == 0) {
        // TODO: Read string and build Z-array
        // TODO: Print Z-array values
    } else if (strcmp(operation, "search") == 0) {
        // TODO: Read pattern and text
        // TODO: Use Z-algorithm to find all occurrences
        // TODO: Print positions or "No match"
    }
    
    return 0;
}
