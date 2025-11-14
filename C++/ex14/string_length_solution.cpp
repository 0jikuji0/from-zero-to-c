// String Length Counter (Exercise 14) - Solution
// Find the longest and shortest string from input.

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    
    string longest = strings[0], shortest = strings[0];
    
    for (int i = 1; i < n; i++) {
        if (strings[i].length() > longest.length()) {
            longest = strings[i];
        }
        if (strings[i].length() < shortest.length()) {
            shortest = strings[i];
        }
    }
    
    cout << longest.length() << " " << longest << endl;
    cout << shortest.length() << " " << shortest << endl;
    
    return 0;
}
