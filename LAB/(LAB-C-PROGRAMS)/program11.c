// PROGRAM: 11
// Question:
// Write a program to find shortest paths to other vertices using Dijkstra’s algorithm,
// from a given vertex in a weighted connected graph.

#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int cost[MAX][MAX], int n, int start) {
    int distance[MAX], visited[MAX];
    int i, j, count, minDistance, nextNode;

    // Initialize distances and visited array
    for (i = 1; i <= n; i++) {
        distance[i] = cost[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    // Dijkstra's main loop
    while (count < n) {
        minDistance = INF;
        nextNode = -1;

        for (i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        if (nextNode == -1)
            break;

        visited[nextNode] = 1;

        for (i = 1; i <= n; i++) {
            if (!visited[i] && (minDistance + cost[nextNode][i] < distance[i])) {
                distance[i] = minDistance + cost[nextNode][i];
            }
        }

        count++;
    }

    // Print results
    printf("\nShortest paths from vertex %d:\n", start);
    for (i = 1; i <= n; i++) {
        if (i != start) {
            if (distance[i] == INF)
                printf("Vertex %d is unreachable.\n", i);
            else
                printf("Vertex %d → Cost = %d\n", i, distance[i]);
        }
    }
}

int main() {
    int n, i, j, start;
    int cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (use %d for no edge):\n", INF);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(cost, n, start);
    return 0;
}
