// PROGRAM: 12
// Question:
// Write a program to implement N Queen’s problem using Backtracking and prove its efficiency.

#include <stdio.h>
#include <stdlib.h>  // For abs()

int board[20], count = 0;

// Function declarations
int place(int row, int column);
void queen(int row, int n);
void print(int n);

int main()
{
    int n;
    printf(" - N Queens Problem Using Backtracking -");
    printf("\n\nEnter number of Queens: ");
    scanf("%d", &n);
    queen(1, n);
    if (count == 0)
        printf("\nNo solution exists for %d Queens.\n", n);
    return 0;
}

int place(int row, int column)
{
    int i;
    for (i = 1; i <= row - 1; i++)
    {
        // Check same column or diagonal conflicts
        if (board[i] == column || abs(board[i] - column) == abs(i - row))
            return 0;
    }
    return 1; // No conflict
}

void queen(int row, int n)
{
    int column;
    for (column = 1; column <= n; column++)
    {
        if (place(row, column))
        {
            board[row] = column;
            if (row == n)
                print(n); // Found a valid arrangement
            else
                queen(row + 1, n);
        }
    }
}

void print(int n)
{
    int i, j;
    printf("\n\nSolution %d:\n\n", ++count);
    for (i = 1; i <= n; i++)
        printf("\t%d", i);

    for (i = 1; i <= n; i++)
    {
        printf("\n\n%d", i);
        for (j = 1; j <= n; j++)
        {
            if (board[i] == j)
                printf("\tQ"); // Queen at (i, j)
            else
                printf("\t-"); // Empty slot
        }
    }
    printf("\n");
}
