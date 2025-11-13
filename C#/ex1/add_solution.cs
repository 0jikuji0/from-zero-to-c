// Solution Ex 1 — Add two integers
using System;

class Program {
    static void Main() {
        string? line = Console.ReadLine();
        if (line == null) return;
        var parts = line.Split(new[]{' ','\t'}, StringSplitOptions.RemoveEmptyEntries);
        int a = 0, b = 0;
        if (parts.Length >= 2) {
            a = int.Parse(parts[0]);
            b = int.Parse(parts[1]);
        } else {
            // fallback: read second value from next line
            a = int.Parse(parts[0]);
            string? line2 = Console.ReadLine();
            if (line2 == null) return;
            b = int.Parse(line2.Trim());
        }
        Console.WriteLine(a + b);
    }
}
