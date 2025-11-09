// Write a program to find shortest paths to other vertices using Dijkstra’s algorithm, from a given vertex in a weighted connected graph.

include<stdio.h> int dijk(int c[10][10], int d[10], int n)
{
    int v[10] = {0}, node, i, j, count, min;
    for (i = 1; i <= n; i++)
    {
        d[i] = c[1][i];
        v[i] = 0;
    }
    v[1] = 1;
    count = 1;
    while (count <= n - 1)
    {
        for (i = 1, min = 9999; i <= n; i++)
        {
            if (d[i] < min && v[i] == 0)
            {
                min = d[i];
                node = i;
            }
        }
        v[node] = 1;
        for (i = 1; i <= n; i++)
        {
            if (!v[i])
            {
                if (min + c[node][i] < d[i])
                    d[i] = min + c[node][i];
            }
        }
        count++;
    }
    for (i = 2; i <= n; i++)
    {
        printf("The least cost path from vertex 1 to vertex %d is %d", i, d[i]);
    }
}
int main()
{
    int i, j;
    int n, d[10], c[10][10];
    printf("Enter the number of nodes");
    scanf("%d", &n);
    printf("Enter the cost matrix:");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            scanf("%d", &c[i][j]);
    }
    dijk(c, d, n);
    return 0;
}