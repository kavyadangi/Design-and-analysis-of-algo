//Code by Kavya
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAX_V 10                                // Maximum number of vertices
#define INF 99999                               // Define infinite
void printSolution(int dist[][MAX_V], int V);   // Function declaration to print the solution matrix
void floyd(int dist[][MAX_V], int V);           // Function declaration for Floyd Warshall algorithm
void floyd(int dist[][MAX_V], int V) {
    int i, j, k;
    for (k = 0; k < V; k++) {                   // Loop through intermediate vertices
        for (j = 0; j < V; j++) {               // Loop through destination vertices
            for (i = 0; i < V; i++) {           // Loop through source vertices
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];    // Update the shortest distance
                }
            }
        }
    }
    printSolution(dist, V);                     // Print the shortest distance matrix
}
void printSolution(int dist[][MAX_V], int V) {
    printf("The following matrix shows the shortest distances between every pair of vertices\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");           // Printing infinity in the matrix
            } else {
                printf("%7d", dist[i][j]);      // Printing distance
            }
        }
        printf("\n");
    }
}
int main() {
    int V, i, j;
    printf("Enter the number of vertices (V <= %d): ", MAX_V);
    scanf("%d", &V);
    int graph[MAX_V][MAX_V];
    printf("Enter the adjacency matrix for the graph:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("Enter distance from vertex %d to %d (INF if no direct edge): ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    floyd(graph, V);                            // Applying Floyd Warshall algorithm
    return 0;
}
