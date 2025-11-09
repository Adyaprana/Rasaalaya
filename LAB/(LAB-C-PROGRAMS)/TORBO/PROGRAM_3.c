// Write a program to convert the given infix expression into its postfix form.

#include <stdio.h>
#include <stdlib.h>
int prec(char c);
char stack[100];
int top = -1;
void push(int num);
char pop();
void infixtopostfix(char str[]);
void main()
{
    char str[100];
    int ch;
    clrscr();
    printf("\nEnter a expression:");
    scanf("%s", str);
    infixtopostfix(str);
}
int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
}
return -1;
void push(int num)
{
    stack[++top] = num;
}
char pop()
{
    char c = stack[top];
    stack[top--] = '\0';
    return (c);
}
void infixtopostfix(char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
            printf("%c", str[i]);
        else if (str[i] == '(')
            push(str[i]);
        else if (str[i] == ')')
        {
            char c;
            do
            {
                c = pop();
                if (c != '(')
                    printf("%c", c);
            }
            else
            {
            }
            while (c != '(')
                ;
            if (stack[top] == '\0' || prec(str[i]) > prec(stack[top]))
            {
            }
            else
            {
                push(str[i]);
                while (prec(str[i]) <= prec(stack[top]))
                {
                    char c = pop();
                    if (c != '(' || c != ')')
                        printf("%c", c);
                    else
                }
                break;
            }
        }
        i++;
    }
    push(str[i]);
    while (top != -1)
        printf("%c", pop());
    getch();
}