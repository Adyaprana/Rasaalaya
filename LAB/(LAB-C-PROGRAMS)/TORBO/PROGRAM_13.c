// Write a program to find a subset of a given set S={s1,s2,….,sn} of n positive integers
// whose sum is equal to a given positive integer d. A suitable message is to be displayed if
// the given problem instance doesn’t have a solution and prove its efficiency

#include <stdio.h>
#include <conio.h>
int s[10], d, n, set[10], count = 0;
void display(int);
int subset(int, int);
int flag = 0;
int main()
{
    int i;
    printf("Enter the number of elements in set\n");
    scanf("%d", &n);
    printf("Enter the set values\n");
    for (i = 0; i < n; ++i)
        scanf("%d", &s[i]);
    printf("Enter the sum\n");
    scanf("%d", &d);
    printf("The progrm output is\n");
    subset(0, 0);
    if (flag == 0)
        printf("there is no solution");
    getch();
    return 0;
}
int subset(int sum, int i)
{
    if (sum == d)
    {
        flag = 1;
        display(count);
        return;
    }
    if (sum > d || i >= n)
        else
        {
        }
}
return;
set[count] = s[i];
count++;
subset(sum + s[i], i + 1);
count--;
subset(sum, i + 1);
void display(int count)
{
    int i;
    printf("{");
    for (i = 0; i < count; i++)
        printf("%d", set[i]);
    printf("}");
}