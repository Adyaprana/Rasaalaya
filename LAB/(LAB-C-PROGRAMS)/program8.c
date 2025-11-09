// PROGRAM: 8
// Question:
// Write a program to compute the transitive closure of a given directed graph
// using Warshall’s algorithm and prove its efficiency.

#include <stdio.h>

#define V 5

// Function to print the matrix
void printMatrix(int reach[V][V]) {
    printf("\n----------------------------------------------------------------");
    printf("\nFollowing matrix is the transitive closure of the given graph:");
    printf("\n----------------------------------------------------------------\n");

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            // Each vertex is reachable from itself
            if (i == j)
                printf("1 ");
            else
                printf("%d ", reach[i][j]);
        }
        printf("\n");
    }
}

// Function to compute transitive closure using Warshall’s algorithm
void transitiveClosure(int graph[V][V]) {
    int reach[V][V];

    // Initialize reach matrix same as the input graph matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            reach[i][j] = graph[i][j];

    // Warshall’s Algorithm
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printMatrix(reach);
}

int main() {
    /* Example directed graph represented as adjacency matrix
       (1 means edge exists, 0 means no edge)
       
          10
      (0)------->(3)
       |        /|\
       |         |
       |         |1
       |         |
       \|/       |
      (1)------->(2)
           3
    */

    int graph[V][V] = {
        {1, 1, 1, 0, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1}
    };

    transitiveClosure(graph);
    printf("\n----------------------------------------------------------------");

    return 0;
}
















// //PROGRAM: 8
// //Question:
// //Write a program to compute the transitive closure of a given directed graph using Warshall’s algorithm and prove its efficiency.

// #define V 5
// #include <stdio.h>
// #include <conio.h>

// void printmatrix(int reach[][V]);

// void transitiveClosure(int graph[][V])
// {
//     int reach[V][V], i, j, k;
//     for (i = 0; i < V; i++)
//         for (j = 0; j < V; j++)
//             reach[i][j] = graph[i][j];

//     for (k = 0; k < V; k++)
//     {
//         for (i = 0; i < V; i++)
//         {
//             for (j = 0; j < V; j++)
//             {
//                 reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
//             }
//         }
//     }
//     printmatrix(reach);
// }

// void printmatrix(int reach[][V])
// {
//     int i,j;
//     printf ("\nFollowing matrix is transitive closure of given graph");
//     for (i = 0; i < V; i++)
//     {
//         for (j = 0; j < V; j++)
//         {
//             if(i == j)
//                 printf("1 ");
//             else
//                 printf ("%d ", reach[i][j]);
//         }
//         printf("\n");
//     }
//     getch();
// }

// int main()
// {
//     /* Let us create the following weighted graph
//           10
//       (0)------->(3)
//        |        /|\
//        |         |
//        |         |1
//        |         |
//        \|/       |
//       (1)------->(2)
//            3
//     */

//     int graph[V][V] = { {1, 1, 1, 0, 0},
//                         {0, 1, 1, 0, 1},
//                         {0, 0, 1, 1, 0},
//                         {0, 0, 0, 1, 1},
//                         {0, 0, 0, 0, 1} };

//     transitiveClosure(graph);
//     return 0;
// }