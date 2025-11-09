//PROGRAM: 5 
//Question: 
//Write a menu driven program to perform insert and delete operations in a circular linked list.

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void beginsert();
void lastinsert();
void begin_delete();
void last_delete();
void display();
void search();

int main() {
    int choice = 0;
    while (choice != 7) {
        printf("\n---------------------------------");
        printf("\nCIRCULAR LINKED LIST OPERATIONS");
        printf("\n---------------------------------");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at Last");
        printf("\n3. Delete from Beginning");
        printf("\n4. Delete from Last");
        printf("\n5. Search for an Element");
        printf("\n6. Display List");
        printf("\n7. Exit");
        printf("\n---------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);  
        switch (choice) {
            case 1: beginsert(); break;
            case 2: lastinsert(); break;
            case 3: begin_delete(); break;
            case 4: last_delete(); break;
            case 5: search(); break;
            case 6: display(); break;
            case 7: exit(0);
            default: printf("\nPlease enter a valid choice.\n");
        }
    }
    return 0;
}

void beginsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }

    printf("\nEnter the node data: ");
    scanf("%d", &item);
    ptr->data = item;

    if (head == NULL) {
        head = ptr;
        ptr->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        ptr->next = head;
        temp->next = ptr;
        head = ptr;
    }
    printf("\nNode inserted at beginning.\n");
}

void lastinsert() {
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));

    if (ptr == NULL) {
        printf("\nOVERFLOW\n");
        return;
    }

    printf("\nEnter Data: ");
    scanf("%d", &item);
    ptr->data = item;

    if (head == NULL) {
        head = ptr;
        ptr->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = ptr;
        ptr->next = head;
    }
    printf("\nNode inserted at end.\n");
}

void begin_delete() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("\nNode deleted; list is now empty.\n");
    } else {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        struct node *temp = head;
        ptr->next = head->next;
        head = head->next;
        free(temp);
        printf("\nNode deleted from beginning.\n");
    }
}

void last_delete() {
    struct node *ptr, *preptr;
    if (head == NULL) {
        printf("\nUNDERFLOW\n");
        return;
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("\nNode deleted; list is now empty.\n");
    } else {
        ptr = head;
        while (ptr->next != head) {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = head;
        free(ptr);
        printf("\nNode deleted from end.\n");
    }
}

void search() {
    struct node *ptr;
    int item, i = 1, flag = 0;

    if (head == NULL) {
        printf("\nEmpty List\n");
        return;
    }

    printf("\nEnter item to search: ");
    scanf("%d", &item);

    ptr = head;
    do {
        if (ptr->data == item) {
            printf("Item found at position %d\n", i);
            flag = 1;
            break;
        }
        ptr = ptr->next;
        i++;
    } while (ptr != head);

    if (!flag)
        printf("Item not found in the list.\n");
}

void display() {
    struct node *ptr;
    if (head == NULL) {
        printf("\nNothing to display.\n");
        return;
    }

    ptr = head;
    printf("\nCircular Linked List Elements:\n");
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
