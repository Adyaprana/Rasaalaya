// Write a menu driven program to implement linear and binary search to find the location of the first occurrence of an item.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void linear();
void binary();
int main()
{
    int choice;
    do
    {
        printf("\n 1. Search the elements using Linear Search");
        printf("\n 2. Search the elements using Binary Search");
        printf("\n 3. Exit");
        printf("\n Enter your choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        case 2:
        case 3:
        }
        linear();
        break;
        binary();
        break;
        exit(0);
        break;
    } while ((choice >= 1) && (choice <= 2));
    return 0;
}
void linear()
{
    int n, c, array[100], search;
    printf("\n Enter the number of elements in an array");
    scanf("%d", &n);
    printf("\n Enter the array elements");
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    printf("\n Enter the number to be searched");
    scanf("%d", &search);
    for (c = 0; c < n; c++)
    {
        if (array[c] == search)
        {
            printf("\n %d is present at the location %d", search, c + 1);
            break;
        }
    }
    if (c == n)
    {
        printf("\n %d is not present in the array", search);
    }
}
void binary()
{
    int array[100], i, j, n, mid, temp, flag = 0, low = 0, high, item, c;
    printf("\n Enter the number of elements in an array");
    scanf("%d", &n);
    printf("\n Enter the array elements");
    for (c = 0; c < n; c++)
        scanf("%d", &array[c]);
    printf("\n Enter the number to be searched");
    scanf("%d", &item);
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == item)
        {
            printf("\n %d is found at the position %d", item, mid);
            flag = 1;
            break;
        }
        else if (item > array[mid])
        {
        }
        else
        {
        }
    }
    low = mid + 1;
    high = mid - 1;
    if (flag == 0)
    {
        printf("\n %d is not found", item);
    }
}