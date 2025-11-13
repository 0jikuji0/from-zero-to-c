// Solution Ex 6 — Longest Increasing Subsequence (O(n log n))
// Uses tails: tails[len-1] = minimum possible tail value for an increasing
// subsequence of length len.

using System;
using System.Collections.Generic;

class Program {
    static int LisLength(List<int> a) {
        if (a == null || a.Count == 0) return 0;
        var tails = new List<int>();
        foreach (var x in a) {
            int i = tails.BinarySearch(x);
            if (i < 0) i = ~i; // insertion point
            if (i == tails.Count) tails.Add(x);
            else tails[i] = x;
        }
        return tails.Count;
    }

    static void Main() {
        if (!int.TryParse(Console.ReadLine(), out int n)) return;
        var tokens = new List<int>();
        while (tokens.Count < n) {
            string? line = Console.ReadLine();
            if (line == null) break;
            foreach (var t in line.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries)) {
                if (tokens.Count >= n) break;
                if (int.TryParse(t, out int v)) tokens.Add(v);
            }
        }
        Console.WriteLine(LisLength(tokens));
    }
}
