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

struct Suffix {
    int index;
    int rank[2];
};

bool cmp(const Suffix& a, const Suffix& b) {
    if (a.rank[0] != b.rank[0])
        return a.rank[0] < b.rank[0];
    return a.rank[1] < b.rank[1];
}

vector<int> buildSuffixArray(const string& text) {
    int n = text.length();
    vector<Suffix> suffixes(n);
    
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank[0] = text[i];
        suffixes[i].rank[1] = (i + 1 < n) ? text[i + 1] : -1;
    }
    
    sort(suffixes.begin(), suffixes.end(), cmp);
    
    vector<int> ind(n);
    
    for (int k = 4; k < 2 * n; k *= 2) {
        int rank = 0;
        int prevRank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;
        
        for (int i = 1; i < n; i++) {
            if (suffixes[i].rank[0] == prevRank &&
                suffixes[i].rank[1] == suffixes[i - 1].rank[1]) {
                prevRank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            } else {
                prevRank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }
        
        for (int i = 0; i < n; i++) {
            int nextIndex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextIndex < n) ? suffixes[ind[nextIndex]].rank[0] : -1;
        }
        
        sort(suffixes.begin(), suffixes.end(), cmp);
    }
    
    vector<int> suffixArr(n);
    for (int i = 0; i < n; i++) {
        suffixArr[i] = suffixes[i].index;
    }
    
    return suffixArr;
}

vector<int> buildLCPArray(const string& text, const vector<int>& suffixArr) {
    int n = text.length();
    vector<int> lcp(n, 0);
    vector<int> invSuff(n);
    
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
    
    return lcp;
}

void longestRepeatedSubstring(const string& text) {
    int n = text.length();
    vector<int> suffixArr = buildSuffixArray(text);
    vector<int> lcp = buildLCPArray(text, suffixArr);
    
    int maxLCP = 0;
    int maxIndex = 0;
    
    for (int i = 0; i < n - 1; i++) {
        if (lcp[i] > maxLCP) {
            maxLCP = lcp[i];
            maxIndex = suffixArr[i];
        }
    }
    
    if (maxLCP == 0) {
        cout << "No repeat" << endl;
    } else {
        cout << text.substr(maxIndex, maxLCP) << endl;
    }
}

void countDistinctSubstrings(const string& text) {
    int n = text.length();
    vector<int> suffixArr = buildSuffixArray(text);
    vector<int> lcp = buildLCPArray(text, suffixArr);
    
    long long total = (long long)n * (n + 1) / 2;
    long long lcpSum = 0;
    
    for (int i = 0; i < n - 1; i++) {
        lcpSum += lcp[i];
    }
    
    cout << total - lcpSum << endl;
}

void longestCommonSubstring(const string& s1, const string& s2) {
    int n1 = s1.length();
    int n2 = s2.length();
    
    string combined = s1 + "#" + s2;
    int n = combined.length();
    
    vector<int> suffixArr = buildSuffixArray(combined);
    vector<int> lcp = buildLCPArray(combined, suffixArr);
    
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
        cout << "No common substring" << endl;
    } else {
        cout << combined.substr(maxIndex, maxLCP) << endl;
    }
}

int main() {
    string operation;
    cin >> operation;
    cin.ignore();
    
    if (operation == "lrs") {
        string text;
        getline(cin, text);
        longestRepeatedSubstring(text);
    } else if (operation == "count") {
        string text;
        getline(cin, text);
        countDistinctSubstrings(text);
    } else if (operation == "lcs") {
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        longestCommonSubstring(s1, s2);
    }
    
    return 0;
}
