// String Reverse (Exercise 10) - Solution
// Reverse a string using C++ STL.

#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    
    reverse(str.begin(), str.end());
    
    cout << str << endl;
    
    return 0;
}
