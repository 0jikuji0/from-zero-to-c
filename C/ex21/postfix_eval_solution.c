/**
 * Exercise 21: Postfix Expression Evaluation
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int* data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = malloc(sizeof(Stack));
    stack->data = malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->data[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return 0;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int evaluatePostfix(char* expr) {
    Stack* stack = createStack(MAX_SIZE);
    
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (strlen(token) == 1 && isOperator(token[0])) {
            int b = pop(stack);
            int a = pop(stack);
            
            switch (token[0]) {
                case '+': push(stack, a + b); break;
                case '-': push(stack, a - b); break;
                case '*': push(stack, a * b); break;
                case '/': push(stack, a / b); break;
            }
        } else {
            push(stack, atoi(token));
        }
        
        token = strtok(NULL, " ");
    }
    
    int result = pop(stack);
    free(stack->data);
    free(stack);
    return result;
}

int main() {
    char expr[MAX_SIZE];
    fgets(expr, MAX_SIZE, stdin);
    
    expr[strcspn(expr, "\n")] = '\0';
    
    int result = evaluatePostfix(expr);
    printf("%d\n", result);
    
    return 0;
}
