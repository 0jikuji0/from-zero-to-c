// Fibonacci (Exercise 9) - Solution
// Generate the n-th Fibonacci number.

using System;

class Program {
    static void Main() {
        int n = int.Parse(Console.ReadLine()!);
        
        if (n == 0) {
            Console.WriteLine(0);
            return;
        }
        
        if (n == 1) {
            Console.WriteLine(1);
            return;
        }
        
        long fib0 = 0, fib1 = 1;
        for (int i = 2; i <= n; i++) {
            long temp = fib0 + fib1;
            fib0 = fib1;
            fib1 = temp;
        }
        
        Console.WriteLine(fib1);
    }
}
