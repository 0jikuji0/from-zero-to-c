// String Reverse (Exercise 12) - Solution
// Reverse a string using C# methods.

using System;
using System.Linq;

class Program {
    static void Main() {
        string? input = Console.ReadLine();
        if (input == null) return;
        
        string reversed = new string(input.Reverse().ToArray());
        
        Console.WriteLine(reversed);
    }
}
