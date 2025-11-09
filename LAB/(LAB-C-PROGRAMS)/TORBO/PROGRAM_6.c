/* Write a menu driven program to perform operations on a stack (linked list
implementation) (push, pop, and peek) */

#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int num;
    struct stack *next;
};
struct stack *top;
void push();
void pop();
void display();
int main()
{
    int choice;
    do
    {
        printf("\n1.Push operation");
        printf("\n2.Pop operation");
        printf("\n3.Display ");
        printf("\n4.Exit ");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    } while (choice >= 1 && choice <= 4);
    return 0;
}
void push()
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    if (temp == NULL)
    {
        puts("\n OVERFLOW CONDITION");
        return;
    }
    printf("\nEnter the value:");
    scanf("%d", &temp->num);
    if (top == NULL)
    {
        top = temp;
    }
    else
    {
        temp->next = top;
        top = temp;
    }
}
void pop()
{
    struct stack *temp;
    if (top == NULL)
    {
    }
    else
    {
        printf("\nUNDERFLOW COMDITION");
        return;
        printf("\n Popped oyt value is = %d", top->num);
        temp = top;
        top = top->next;
        free(temp);
    }
}
void display()
{
    struct stack *temp;
    if (top == NULL)
    {
        printf("\n NO ELEMENTS TO DISPLAY>>\n STACK IS EMPTY");
        return;
    }
    for (temp = top; temp != NULL; temp = temp->next)
        printf("\n%d\n", temp->num);
}
