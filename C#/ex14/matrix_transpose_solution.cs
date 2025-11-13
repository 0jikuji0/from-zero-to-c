// Matrix Transpose (Exercise 14) - Solution
// Transpose a matrix (swap rows and columns).

using System;
using System.Collections.Generic;

class Program {
    static void Main() {
        int m = int.Parse(Console.ReadLine()!);
        string? nLine = Console.ReadLine();
        if (nLine == null) return;
        
        var parts = nLine.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
        if (parts.Length < 1) return;
        int n = int.Parse(parts[0]);
        
        List<List<int>> matrix = new List<List<int>>();
        
        for (int i = 0; i < m; i++) {
            string? row = Console.ReadLine();
            if (row == null) return;
            
            var rowParts = row.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
            List<int> rowList = new List<int>();
            foreach (string part in rowParts) {
                if (int.TryParse(part, out int val)) {
                    rowList.Add(val);
                }
            }
            matrix.Add(rowList);
        }
        
        List<List<int>> transposed = new List<List<int>>();
        for (int i = 0; i < n; i++) {
            transposed.Add(new List<int>());
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transposed[j].Add(matrix[i][j]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            Console.WriteLine(string.Join(" ", transposed[i]));
        }
    }
}
