/**
 * Exercise 42: Aho-Corasick Algorithm (Multi-Pattern Matching)
 * Difficulty: ***** (5/5)
 * 
 * Implement the Aho-Corasick algorithm for finding multiple patterns
 * in a text simultaneously. This algorithm builds a finite state machine
 * (trie + failure links) to achieve O(n + m + z) complexity where:
 * - n = total length of all patterns
 * - m = text length
 * - z = number of pattern occurrences
 * 
 * Applications:
 * - Antivirus scanning
 * - Intrusion detection systems
 * - DNA sequence matching
 * - Text editors (find multiple keywords)
 * 
 * Input:
 * - First line: number of patterns k
 * - Next k lines: patterns to search for
 * - Last line: text to search in
 * 
 * Output:
 * - For each pattern found, print: "Pattern 'X' found at position Y"
 * - If no patterns found, print: "No patterns found"
 * - Output sorted by position, then by pattern index
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CHARS 26
#define MAX_PATTERNS 100
#define MAX_LEN 1005

// TODO: Define trie node structure with:
//       - children array (26 letters)
//       - failure link
//       - output link (which patterns end here)

// TODO: Implement function to create new trie node

// TODO: Implement function to insert pattern into trie

// TODO: Implement function to build failure links (BFS-based)

// TODO: Implement function to search text using the automaton

int main() {
    int k;
    scanf("%d", &k);
    getchar();
    
    // TODO: Read k patterns and build trie
    // TODO: Build failure links
    // TODO: Read text and search for all patterns
    // TODO: Print results sorted by position
    
    return 0;
}
