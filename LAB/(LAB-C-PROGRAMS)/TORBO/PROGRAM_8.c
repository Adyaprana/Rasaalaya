// Write a program to compute the transitive closure of a given direted graph using Warshall’s algorithm and prove its efficiency

#define V 5 
void printmatrix(int reach[][V]);
void transitiveClosure(int graph[][V])
{
    int reach[V][V], i, j, k;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            reach[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                reach[i][j] = reach[i][j] ||
                              (reach[i][k] && reach[k][j]);
            }
        }
    }
    printmatrix(reach);
}
void printmatrix(int reach[][V])
{
    int i, j;
    printf("\nFollowing matrix is transitive closure of given graph");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (i == j)
                printf("1 ");
        }
        printf("\n");
        getch();
    }
}
else printf("%d ", reach[i][j]);
int main()
{
    int graph[V][V] = {{1, 1, 1, 0, 0},
                       {0, 1, 1, 0, 1},
                       {0, 0, 1, 1, 0},
                       {0, 0, 0, 1, 1},
                       {0, 0, 0, 0, 1}};
    transitiveClosure(graph);
    return 0;
}