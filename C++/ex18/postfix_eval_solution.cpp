/**
 * Exercise 18: Postfix Expression Evaluation
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

#include <bits/stdc++.h>
using namespace std;

bool isOperator(const string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

int evaluatePostfix(const string& expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;
    
    while (ss >> token) {
        if (isOperator(token)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }
    
    return st.top();
}

int main() {
    string line;
    getline(cin, line);
    
    int result = evaluatePostfix(line);
    cout << result << "\n";
    
    return 0;
}
