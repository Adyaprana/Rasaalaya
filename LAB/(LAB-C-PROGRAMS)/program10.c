// PROGRAM: 10
// Question:
// Write a program to implement 0/1 Knapsack problem using dynamic programming and prove its efficiency.

#include <stdio.h>

int main() {
    int i, j, n, m;
    int p[50], w[50], v[50][50];

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);

    printf("Enter the profit for each object:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &p[i]);

    printf("Enter the weight for each object:\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    // Initialize and compute the DP table
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else {
                int include = v[i - 1][j - w[i]] + p[i];
                int exclude = v[i - 1][j];
                v[i][j] = (include > exclude) ? include : exclude;
            }
        }
    }

    printf("\nMaximum profit earned = %d\n", v[n][m]);

    // Optional: display DP table for understanding
    printf("\nDynamic Programming Table:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%3d ", v[i][j]);
        }
        printf("\n");
    }

    return 0;
}
