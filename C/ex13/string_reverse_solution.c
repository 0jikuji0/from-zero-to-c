// String Reverse (Exercise 13) - Solution
// Reverse a string in-place.

#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);
    
    int len = strlen(str);
    int left = 0, right = len - 1;
    
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }
    
    printf("%s\n", str);
    
    return 0;
}
