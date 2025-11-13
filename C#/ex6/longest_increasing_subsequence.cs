// Exercise 6 — Longest Increasing Subsequence (LIS)
// Difficulty: Medium
//
// Problem: read an integer n (1 ≤ n ≤ 100000) followed by n integers and
// print the length of the longest strictly increasing subsequence (LIS).
//
// Input format:
// n
// a1 a2 ... an
//
// Output format:
// length_of_the_LIS
//
// Hints / TODOs:
// - Implement `int LisLength(List<int> a)`.
// - You can implement an O(n log n) algorithm (recommended) using tails
//   and binary search, or an O(n^2) DP algorithm for simpler code.

using System;
using System.Collections.Generic;

class Program {
    static int LisLength(List<int> a) {
        // TODO: implement LIS algorithm and return its length
        return 0;
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
