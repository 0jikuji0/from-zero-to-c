// Exercise 7 — Reference Swap
// Difficulty: Easy
//
// Problem: read two integers a and b, then swap them using a function that
// takes ref parameters. Print the swapped values.
//
// Input format:
// a b
//
// Output format:
// a b  (swapped)
//
// Hints / TODOs:
// - TODO 1: implement `void Swap(ref int x, ref int y)` that swaps via ref.
// - TODO 2: read two integers a and b.
// - TODO 3: call Swap and print the result.
//
// Key concept: using C# `ref` keyword to pass variables by reference.

using System;

class Program {
    // TODO: implement void Swap(ref int x, ref int y)

    static void Main() {
        int a, b;

        // TODO 1: read two integers a and b
        string? line = Console.ReadLine();
        if (line == null) return;
        var parts = line.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
        if (parts.Length < 2) return;
        if (!int.TryParse(parts[0], out a) || !int.TryParse(parts[1], out b)) return;

        // TODO 2: call Swap(ref a, ref b);
        // Swap(ref a, ref b);

        // TODO 3: print swapped values
        Console.WriteLine($"{a} {b}");
    }
}
