// PROGRAM: 4
// Question:
// Write a menu-driven program to create a linked list and to perform insert and delete operations.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

int main()
{
    int choice = 0;

    while (choice != 9)
    {
        printf("\n-----------------------------");
        printf("\n        LINKED LIST MENU      ");
        printf("\n-----------------------------");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at last");
        printf("\n3. Insert at specific position");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from last");
        printf("\n6. Delete from specific position");
        printf("\n7. Search for an element");
        printf("\n8. Display list");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            randominsert();
            break;
        case 4:
            begin_delete();
            break;
        case 5:
            last_delete();
            break;
        case 6:
            random_delete();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;
        case 9:
            printf("\nExiting...\n");
            exit(0);
        default:
            printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

void beginsert()
{
    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = head;
    head = ptr;
    printf("\nNode inserted at beginning.\n");
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    printf("\nEnter value: ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
        printf("\nNode inserted as first element.\n");
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
        printf("\nNode inserted at last.\n");
    }
}

void randominsert()
{
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    printf("\nEnter element value: ");
    scanf("%d", &item);
    printf("\nEnter the location after which you want to insert: ");
    scanf("%d", &loc);
    ptr->data = item;
    temp = head;
    for (i = 0; i < loc - 1; i++)
    {
        if (temp == NULL)
        {
            printf("\nCan't insert — location not found.\n");
            free(ptr);
            return;
        }
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    printf("\nNode inserted at position %d.\n", loc);
}

void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    ptr = head;
    head = ptr->next;
    free(ptr);
    printf("\nNode deleted from beginning.\n");
}

void last_delete()
{
    struct node *ptr, *prev;
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("\nOnly node deleted.\n");
        return;
    }
    ptr = head;
    while (ptr->next != NULL)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    prev->next = NULL;
    free(ptr);
    printf("\nNode deleted from last.\n");
}

void random_delete()
{
    struct node *ptr, *prev;
    int loc, i;
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nEnter the location to delete: ");
    scanf("%d", &loc);

    if (loc == 1)
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\nNode deleted at position 1.\n");
        return;
    }

    ptr = head;
    for (i = 1; i < loc && ptr != NULL; i++)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\nLocation not found.\n");
        return;
    }
    prev->next = ptr->next;
    free(ptr);
    printf("\nNode deleted at position %d.\n", loc);
}

void search()
{
    struct node *ptr;
    int item, i = 1, flag = 0;
    if (head == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nEnter item to search: ");
    scanf("%d", &item);
    ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == item)
        {
            printf("\nItem found at position %d.\n", i);
            flag = 1;
            break;
        }
        i++;
        ptr = ptr->next;
    }
    if (!flag)
        printf("\nItem not found.\n");
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nCurrent Linked List: ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
