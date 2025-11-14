// String Length Counter (Exercise 16) - Solution
// Find the longest and shortest string from input.

using System;
using System.Collections.Generic;
using System.Linq;

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine()!);
        
        List<string> strings = new List<string>();
        for (int i = 0; i < n; i++) {
            string? s = Console.ReadLine();
            if (s != null) {
                strings.Add(s);
            }
        }
        
        if (strings.Count == 0) return;
        
        string longest = strings.OrderByDescending(s => s.Length).First();
        string shortest = strings.OrderBy(s => s.Length).First();
        
        Console.WriteLine($"{longest.Length} {longest}");
        Console.WriteLine($"{shortest.Length} {shortest}");
    }
}
