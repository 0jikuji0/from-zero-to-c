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

void computeZArray(const char* str, int n, int* Z) {
    Z[0] = n;
    int L = 0, R = 0;
    
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R - L] == str[R]) {
                R++;
            }
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while (R < n && str[R - L] == str[R]) {
                    R++;
                }
                Z[i] = R - L;
                R--;
            }
        }
    }
}

void buildZArray(const char* str) {
    int n = strlen(str);
    int* Z = (int*)malloc(sizeof(int) * n);
    
    computeZArray(str, n, Z);
    
    for (int i = 0; i < n; i++) {
        printf("%d", Z[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    free(Z);
}

void searchPattern(const char* pattern, const char* text) {
    int m = strlen(pattern);
    int n = strlen(text);
    
    char* combined = (char*)malloc(sizeof(char) * (m + n + 2));
    sprintf(combined, "%s$%s", pattern, text);
    
    int len = strlen(combined);
    int* Z = (int*)malloc(sizeof(int) * len);
    
    computeZArray(combined, len, Z);
    
    bool found = false;
    for (int i = m + 1; i < len; i++) {
        if (Z[i] == m) {
            if (found) printf(" ");
            printf("%d", i - m - 1);
            found = true;
        }
    }
    
    if (!found) {
        printf("No match");
    }
    printf("\n");
    
    free(combined);
    free(Z);
}

int main() {
    char operation[10];
    scanf("%s", operation);
    getchar();
    
    if (strcmp(operation, "build") == 0) {
        char str[MAX_LEN];
        fgets(str, MAX_LEN, stdin);
        str[strcspn(str, "\n")] = 0;
        buildZArray(str);
    } else if (strcmp(operation, "search") == 0) {
        char pattern[MAX_LEN];
        char text[MAX_LEN];
        fgets(pattern, MAX_LEN, stdin);
        fgets(text, MAX_LEN, stdin);
        pattern[strcspn(pattern, "\n")] = 0;
        text[strcspn(text, "\n")] = 0;
        searchPattern(pattern, text);
    }
    
    return 0;
}
