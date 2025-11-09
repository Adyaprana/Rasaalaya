// PROGRAM: 9
// Question:
// Write a program to find the Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm.

#include <stdio.h>

int main() {
    int cost[10][10];
    int visited[10] = {0};
    int n, i, j, ne = 1;
    int min, a, b, u, v, mincost = 0;

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999; // 999 = infinity (no edge)
        }
    }

    visited[1] = 1; // Start from node 1

    printf("\nEdges of Minimum Cost Spanning Tree:\n");

    while (ne < n) {
        min = 999;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    if (visited[i] != 0) {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        if (visited[u] == 0 || visited[v] == 0) {
            printf("\nEdge %d: (%d -> %d)  cost = %d", ne++, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = 999; // remove this edge from consideration
    }

    printf("\n\nMinimum cost = %d\n", mincost);

    return 0;
}
