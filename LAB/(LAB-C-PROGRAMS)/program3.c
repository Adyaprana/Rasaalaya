// PROGRAM: 3
// Question:
// Write a program to convert the given infix expression into its postfix form.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char str[]) {
    char postfix[100];
    int i = 0, k = 0;
    char c;

    while (str[i] != '\0') {
        // Operand (A–Z or a–z)
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            postfix[k++] = str[i];
        // Left parenthesis
        else if (str[i] == '(')
            push(str[i]);
        // Right parenthesis
        else if (str[i] == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); // Remove '('
        }
        // Operator
        else {
            while (top != -1 && prec(str[i]) <= prec(stack[top]))
                postfix[k++] = pop();
            push(str[i]);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0'; // null terminate
    printf("\nPostfix expression: %s\n", postfix);
}

int main() {
    char expr[100];
    printf("\n-----------------------------");
    printf("\n       infix to postfix      ");
    printf("\n-----------------------------");
    printf("\nEnter an infix expression: ");
    scanf("%s", expr);
    infixToPostfix(expr);
    return 0;
}
