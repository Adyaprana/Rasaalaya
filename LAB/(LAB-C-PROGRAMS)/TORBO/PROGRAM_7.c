/*Write a menu driven program to perform operations on a circular queue (enqueue,dequeue and peek). */

#include <stdio.h>
#include <stdlib.h>
typedefstruct queue
{
    int data;
    struct queue *link;
}
queue;
queue *front = NULL, *rear = NULL;
void enqueue();
int dequeue();
void display();
queue *create();
int main()
{
    int ch = 6;
    while (ch != 5)
    {
        printf("\n1.create\n2.enqueue\n3.dequeue\n4.display\n5.exit\nenter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (front == NULL)
            {
            }
            else
                break;
            rear = front = create();
            printf("queue already exists\n");
        case 2:
            enqueue();
            break;
        case 3:
            if (front == NULL)
                printf("queue underflow\n");
            else
                break;
            printf("deleted item : %d ", dequeue());
        case 4:
            display();
            break;
        default:
            break;
        }
    }
    return 0;
}
queue *create()
{
    queue *temp = (queue *)malloc(sizeof(queue));
    printf("enter data\n");
    scanf("%d", &temp->data);
    temp->link = front;
    return temp;
}
void enqueue()
{
    rear->link = create();
    rear = rear->link;
}
int dequeue()
{
    queue *temp = front;
    int ch = front->data;
    if (front == rear)
        front = rear = NULL;
    else
    {
    }
    front = front->link;
    rear->link = front;
    free(temp);
    return ch;
}
void display()
{
    queue *temp = front;
    printf("\ncircular queue\n");
    if (temp == rear)
        printf("%d", temp->data);
    else if (front == NULL)
        printf("queue is empty\n");
    else
    {
        int i = 0;
        do
        {
            printf("%d ", temp->data);
            temp = temp->link;
            i++;
        } while (temp != front);
    }
}