// String Length Counter (Exercise 17) - Solution
// Find the longest and shortest string from input.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char **strings = (char **)malloc(n * sizeof(char *));
    if (strings == NULL) {
        return 1;
    }
    
    for (int i = 0; i < n; i++) {
        char temp[256];
        scanf("%s", temp);
        strings[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
        if (strings[i] == NULL) {
            return 1;
        }
        strcpy(strings[i], temp);
    }
    
    int maxLen = 0, minLen = INT_MAX;
    char *longest = NULL, *shortest = NULL;
    
    for (int i = 0; i < n; i++) {
        int len = strlen(strings[i]);
        if (len > maxLen) {
            maxLen = len;
            longest = strings[i];
        }
        if (len < minLen) {
            minLen = len;
            shortest = strings[i];
        }
    }
    
    printf("%d %s\n", maxLen, longest);
    printf("%d %s\n", minLen, shortest);
    
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }
    free(strings);
    
    return 0;
}
