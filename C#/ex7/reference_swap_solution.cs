// Reference Swap (Exercise 7) - Solution
// Demonstrates C# ref parameters for swapping values.

using System;

class Program {
    static void Swap(ref int x, ref int y) {
        int tmp = x;
        x = y;
        y = tmp;
    }

    static void Main() {
        int a, b;

        string? line = Console.ReadLine();
        if (line == null) return;
        var parts = line.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
        if (parts.Length < 2) return;
        if (!int.TryParse(parts[0], out a) || !int.TryParse(parts[1], out b)) return;

        Swap(ref a, ref b);
        Console.WriteLine($"{a} {b}");
    }
}
