//PROGRAM: 6
//Question:
//Write a menu driven program to perform operations on a stack (linked list implementation) (push, pop, and peek).

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int num;
    struct stack *next;
};

struct stack *top = NULL;   

void push();
void pop();
void display();

int main()
{
    int choice;

    while (1) 
    {   
        printf("\n---------------------------------");
        printf("\n     Operations on a stack       ");
        printf("\n---------------------------------");
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
                printf("\nExiting program...\n");
                exit(0);  
            default:
                printf("\nInvalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

void push()
{
    struct stack *temp;
    temp = (struct stack *)malloc(sizeof(struct stack));
    if (temp == NULL)
    {
        puts("\nOVERFLOW CONDITION");
        return;
    }
    printf("\nEnter the value: ");
    scanf("%d", &temp->num);
    temp->next = top;  
    top = temp;
    printf("\n%d pushed into stack.\n", temp->num);
}

void pop()
{
    struct stack *temp;
    if (top == NULL)
    {
        printf("\nUNDERFLOW CONDITION");
        return;
    }
    else
    {
        printf("\nPopped out value = %d", top->num);
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
        printf("\nNO ELEMENTS TO DISPLAY >> STACK IS EMPTY\n");
        return;
    }
    printf("\nCurrent Stack Elements:\n");
    for (temp = top; temp != NULL; temp = temp->next)
        printf("%d\n", temp->num);
}
