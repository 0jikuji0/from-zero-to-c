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

typedef struct {
    int index;
    int rank[2];
} Suffix;

int cmp(const void* a, const void* b) {
    Suffix* s1 = (Suffix*)a;
    Suffix* s2 = (Suffix*)b;
    
    if (s1->rank[0] != s2->rank[0]) {
        return s1->rank[0] - s2->rank[0];
    }
    return s1->rank[1] - s2->rank[1];
}

void buildSuffixArray(const char* text, int n, int* suffixArr) {
    Suffix* suffixes = (Suffix*)malloc(sizeof(Suffix) * n);
    
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = text[i];
        suffixes[i].rank[1] = (i + 1 < n) ? text[i + 1] : -1;
    }
    
    qsort(suffixes, n, sizeof(Suffix), cmp);
    
    int* ind = (int*)malloc(sizeof(int) * n);
    
    for (int k = 4; k < 2 * n; k *= 2) {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
        
        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prev_rank && 
                suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int nextIndex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextIndex < n) ? suffixes[ind[nextIndex]].rank[0] : -1;
        }
        
        qsort(suffixes, n, sizeof(Suffix), cmp);
    }
    
    for (int i = 0; i < n; i++) {
        suffixArr[i] = suffixes[i].index;
    }
    
    free(suffixes);
    free(ind);
}

void buildLCPArray(const char* text, int n, int* suffixArr, int* lcp) {
    int* invSuff = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        invSuff[suffixArr[i]] = i;
    }
    
    int k = 0;
    
    for (int i = 0; i < n; i++) {
        if (invSuff[i] == n - 1) {
            k = 0;
            continue;
        }
        
        int j = suffixArr[invSuff[i] + 1];
        
        while (i + k < n && j + k < n && text[i + k] == text[j + k]) {
            k++;
        }
        
        lcp[invSuff[i]] = k;
        
        if (k > 0) {
            k--;
        }
    }
    
    free(invSuff);
}

void longestRepeatedSubstring(const char* text, int n) {
    int* suffixArr = (int*)malloc(sizeof(int) * n);
    int* lcp = (int*)malloc(sizeof(int) * n);
    
    buildSuffixArray(text, n, suffixArr);
    buildLCPArray(text, n, suffixArr, lcp);
    
    int maxLCP = 0;
    int maxIndex = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (lcp[i] > maxLCP) {
            maxLCP = lcp[i];
            maxIndex = suffixArr[i];
        }
    }
    
    if (maxLCP == 0) {
        printf("No repeat\n");
    } else {
        for (int i = 0; i < maxLCP; i++) {
            printf("%c", text[maxIndex + i]);
        }
        printf("\n");
    }
    
    free(suffixArr);
    free(lcp);
}

void countDistinctSubstrings(const char* text, int n) {
    int* suffixArr = (int*)malloc(sizeof(int) * n);
    int* lcp = (int*)malloc(sizeof(int) * n);
    
    buildSuffixArray(text, n, suffixArr);
    buildLCPArray(text, n, suffixArr, lcp);
    
    long long total = (long long)n * (n + 1) / 2;
    long long lcpSum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        lcpSum += lcp[i];
    }
    
    printf("%lld\n", total - lcpSum);
    
    free(suffixArr);
    free(lcp);
}

void longestCommonSubstring(const char* s1, const char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    
    char* combined = (char*)malloc(sizeof(char) * (n1 + n2 + 2));
    strcpy(combined, s1);
    combined[n1] = '#';
    strcpy(combined + n1 + 1, s2);
    
    int n = n1 + n2 + 1;
    
    int* suffixArr = (int*)malloc(sizeof(int) * n);
    int* lcp = (int*)malloc(sizeof(int) * n);
    
    buildSuffixArray(combined, n, suffixArr);
    buildLCPArray(combined, n, suffixArr, lcp);
    
    int maxLCP = 0;
    int maxIndex = 0;
    
    for (int i = 0; i < n - 1; i++) {
        bool first = (suffixArr[i] < n1);
        bool second = (suffixArr[i + 1] > n1);
        
        if ((first && second) || (second && first)) {
            if (lcp[i] > maxLCP) {
                maxLCP = lcp[i];
                maxIndex = suffixArr[i];
            }
        }
    }
    
    if (maxLCP == 0) {
        printf("No common substring\n");
    } else {
        for (int i = 0; i < maxLCP; i++) {
            printf("%c", combined[maxIndex + i]);
        }
        printf("\n");
    }
    
    free(combined);
    free(suffixArr);
    free(lcp);
}

int main() {
    char operation[10];
    scanf("%s", operation);
    getchar();
    
    if (strcmp(operation, "lrs") == 0) {
        char text[MAX_N];
        fgets(text, MAX_N, stdin);
        text[strcspn(text, "\n")] = 0;
        int n = strlen(text);
        longestRepeatedSubstring(text, n);
    } else if (strcmp(operation, "count") == 0) {
        char text[MAX_N];
        fgets(text, MAX_N, stdin);
        text[strcspn(text, "\n")] = 0;
        int n = strlen(text);
        countDistinctSubstrings(text, n);
    } else if (strcmp(operation, "lcs") == 0) {
        char s1[MAX_N], s2[MAX_N];
        fgets(s1, MAX_N, stdin);
        fgets(s2, MAX_N, stdin);
        s1[strcspn(s1, "\n")] = 0;
        s2[strcspn(s2, "\n")] = 0;
        longestCommonSubstring(s1, s2);
    }
    
    return 0;
}
