//PROGRAM: 7
//Question:
//Write a menu driven program to perform operations on a circular queue (enqueue, dequeue and peek).

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *link;
} queue;

queue *front = NULL, *rear = NULL;

void enqueue();
int dequeue();
void display();
queue *create();
void peek();
int main()
{
    int ch;
    while (1)
    {
        printf("\n---------------------------------");
        printf("\n    CIRCULAR QUEUE OPERATIONS    ");
        printf("\n---------------------------------");
        printf("\n1. Create");
        printf("\n2. Enqueue");
        printf("\n3. Dequeue");
        printf("\n4. Display");
        printf("\n5. Peek");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                if (front == NULL)
                {
                    rear = front = create();
                    printf("Queue created successfully.\n");
                }
                else
                {
                    printf("Queue already exists!\n");
                }
                break;

            case 2:
                enqueue();
                break;

            case 3:
                if (front == NULL)
                    printf("Queue Underflow! (Empty queue)\n");
                else
                    printf("Deleted item: %d\n", dequeue());
                break;

            case 4:
                display();
                break;

            case 5:
                peek();
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}

queue *create()
{
    queue *temp = (queue *)malloc(sizeof(queue));
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d", &temp->data);
    temp->link = temp; // initially circular
    return temp;
}

void enqueue()
{
    if (front == NULL)
    {
        rear = front = create();
    }
    else
    {
        queue *temp = (queue *)malloc(sizeof(queue));
        if (temp == NULL)
        {
            printf("Overflow! Memory allocation failed.\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d", &temp->data);
        temp->link = front;
        rear->link = temp;
        rear = temp;
    }
    printf("Item inserted successfully.\n");
}

int dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return -1;
    }

    queue *temp = front;
    int value = temp->data;

    if (front == rear) // only one element
    {
        front = rear = NULL;
    }
    else
    {
        front = front->link;
        rear->link = front;
    }

    free(temp);
    return value;
}

void display()
{
    if (front == NULL)
    {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("\nCircular Queue Elements:\n");
    queue *temp = front;
    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while (temp != front);
    printf("\n");
}

void peek()
{
    if (front == NULL)
        printf("\nQueue is empty (no front element).\n");
    else
        printf("\nFront element is: %d\n", front->data);
}
