// Is Prime (Exercise 10) - Solution
// Check if a given number is prime.

using System;

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine()!);
        
        if (n < 2) {
            Console.WriteLine("false");
            return;
        }
        
        if (n == 2) {
            Console.WriteLine("true");
            return;
        }
        
        if (n % 2 == 0) {
            Console.WriteLine("false");
            return;
        }
        
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                Console.WriteLine("false");
                return;
            }
        }
        
        Console.WriteLine("true");
    }
}
