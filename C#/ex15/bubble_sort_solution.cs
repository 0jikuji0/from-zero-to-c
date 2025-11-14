// Bubble Sort (Exercise 15) - Solution
// Sort a list using bubble sort algorithm.

using System;
using System.Collections.Generic;

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine()!);
        
        string? line = Console.ReadLine();
        if (line == null) return;
        
        var parts = line.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
        List<int> lst = new List<int>();
        foreach (string part in parts) {
            if (int.TryParse(part, out int val)) {
                lst.Add(val);
            }
        }
        
        for (int i = 0; i < lst.Count - 1; i++) {
            for (int j = 0; j < lst.Count - i - 1; j++) {
                if (lst[j] > lst[j + 1]) {
                    int temp = lst[j];
                    lst[j] = lst[j + 1];
                    lst[j + 1] = temp;
                }
            }
        }
        
        Console.WriteLine(string.Join(" ", lst));
    }
}
