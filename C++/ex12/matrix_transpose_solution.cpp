// Matrix Transpose (Exercise 12) - Solution
// Transpose a matrix (swap rows and columns).

#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> matrix(m, vector<int>(n));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    vector<vector<int>> transposed(n, vector<int>(m));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << transposed[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
