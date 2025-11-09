//PROGRAM: 10
//Question:
//Write a program to implement 0/1 Knapsack problem using dynamic programming and prove its efficiency.

#include <stdio.h>
#include <conio.h>

void main()
{
    int i,j,n,m,p[50],w[50],v[50][50];
    clrscr();

    printf("Enter the number of objects \n");
    scanf("%d",&n);

    printf("Enter the capacity of knapsack \n");
    scanf("%d",&m);

    printf("Enter the profit for objects \n");
    for (i=1;i<=n;i++)
        scanf("%d",&p[i]);

    printf("Enter the weights for objects \n");
    for (i=1;i<=n;i++)
        scanf("%d",&w[i]);

    for (i=1;i<=n;i++)
        for(j=0;j<=m;j++)
        {
            if (i==0 || j==0)
                v[i][j]=0;
            else if (w[i]>j)
                v[i][j]=v[i-1][j];
            else
            {
                if(v[i-1][j]>v[i-1][j-w[i]]+p[i])
                {
                    v[i][j]=v[i-1][j];
                }
                else
                {
                    v[i][j]=v[i-1][j-w[i]]+p[i];
                }
            }
        }

    printf("The profit earned is : %d",v[n][m]);
    getch();
}