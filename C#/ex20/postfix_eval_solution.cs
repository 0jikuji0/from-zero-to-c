/**
 * Exercise 20: Postfix Expression Evaluation
 * Difficulty: **** (4/5)
 * 
 * Implement postfix (Reverse Polish Notation) expression evaluation using a stack.
 * In postfix notation, operators come after operands (e.g., "3 4 +" instead of "3 + 4").
 * 
 * Input:
 * - A single line containing a postfix expression with space-separated tokens
 * 
 * Output:
 * - Print the result of the postfix expression evaluation
 */

using System;
using System.Collections.Generic;

class Program {
    static bool IsOperator(string token) {
        return token == "+" || token == "-" || token == "*" || token == "/";
    }
    
    static int EvaluatePostfix(string expr) {
        Stack<int> stack = new Stack<int>();
        string[] tokens = expr.Split(' ');
        
        foreach (string token in tokens) {
            if (IsOperator(token)) {
                int b = stack.Pop();
                int a = stack.Pop();
                
                switch (token) {
                    case "+": stack.Push(a + b); break;
                    case "-": stack.Push(a - b); break;
                    case "*": stack.Push(a * b); break;
                    case "/": stack.Push(a / b); break;
                }
            } else {
                stack.Push(int.Parse(token));
            }
        }
        
        return stack.Pop();
    }
    
    static void Main() {
        string line = Console.ReadLine();
        
        int result = EvaluatePostfix(line);
        Console.WriteLine(result);
    }
}
