// GCD (Exercise 13) - Solution
// Find the Greatest Common Divisor of two numbers.

using System;

class Program {
    static int ComputeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    static void Main() {
        string? line = Console.ReadLine();
        if (line == null) return;
        
        var parts = line.Split(new[]{' ', '\t'}, StringSplitOptions.RemoveEmptyEntries);
        if (parts.Length < 2) return;
        
        if (int.TryParse(parts[0], out int a) && int.TryParse(parts[1], out int b)) {
            Console.WriteLine(ComputeGCD(a, b));
        }
    }
}
