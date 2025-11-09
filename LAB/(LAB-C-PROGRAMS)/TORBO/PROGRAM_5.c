// Write a menu driven program to perform insert and delete operations in a circular linked list.

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void main()
{
    int choice = 0;
    while (choice != 7)
    {
        printf("\nCIRCULAR LINKED LIST");
        printf("\nChoose one option from the following list");
printf("\n1.Insert in begining\n2.Insert at last\n3.Delete from Beginning\n4.Delete from
last\n5.Search for an element\n6.Show\n7.Exit\n");
printf("\nEnter your choice?");
scanf("\n%d",&choice);
switch(choice)
{
        case 1:
        case 2:
            beginsert();
            break;
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            lastinsert();
            break;
            begin_delete();
            break;
            last_delete();
            break;
            search();
            break;
            display();
            break;
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
}
    }
}
void beginsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
    }
    else
    {
        printf("\nOVERFLOW");
        printf("\nEnter the node data?");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
        }
        else
        {
        }
        head = ptr;
        ptr->next = head;
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
        printf("\nnode inserted\n");
    }
}
void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
    }
    else
    {
        printf("\nOVERFLOW\n");
        printf("\nEnter Data?");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
        }
        else
        {
            ptr->next = head;
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        printf("\nnode inserted\n");
    }
}
void begin_delete()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
    }
    else
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nnode deleted\n");
    }
}
void last_delete()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
    }
    else
    {
        head = NULL;
        free(head);
        printf("\nnode deleted\n");
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
void search()
{
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
    }
    else
    {
        printf("\nEmpty List\n");
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        if (head->data == item)
        {
        }
        else
        {
            printf("item found at location %d", i + 1);
            flag = 0;
            while (ptr->next != head)
            {
                if (ptr->data == item)
                {
                }
                else
                {
                }
                i++;
                printf("item found at location %d ", i + 1);
                flag = 0;
                break;
                flag = 1;
                ptr = ptr->next;
            }
        }
        if (flag != 0)
        {
            printf("Item not found\n");
        }
    }
}
void display()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
    }
    else
    {
        printf("\nnothing to print");
        printf("\n printing values ... \n");
        while (ptr->next != head)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}