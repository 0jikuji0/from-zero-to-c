// Solution Ex 2 — Palindrome
using System;

class Program {
    static void Main() {
        string? s = Console.ReadLine();
        if (s == null) return;
        s = s.Trim();
        int i = 0, j = s.Length - 1;
        bool ok = true;
        while (i < j) {
            if (s[i] != s[j]) { ok = false; break; }
            i++; j--;
        }
        Console.WriteLine(ok ? "YES" : "NO");
    }
}
