//Code by Kavya
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int V;  // Number of vertices in the graph
// Function to perform the Bellman-Ford algorithm to find the shortest paths from a source vertex
void bellman(int **graph, int src) {
    int dist[V];  // Array to store the shortest distances from the source vertex
    // Initialize distances to all vertices as INFINITE
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    // Distance from source to itself is always 0
    dist[src] = 0;
    int x = 0;
    while (x != V - 1) {
        // Relax all edges V-1 times
        for (int i = 0; i < V; i++) {
            for (int j = 1; j < V; j++) {
                // Update the distance if the current path is shorter than the previously calculated distance
                if (graph[i][j] && dist[i] != INT_MAX && dist[i] + graph[i][j] < dist[j]) {
                    dist[j] = dist[i] + graph[i][j];
                }
            }
        }
        x++;
    }
    // Check for negative cycles
    for (int i = 0; i < V; i++) {
        for (int j = 1; j < V; j++) {
            if (graph[i][j] && dist[i] != INT_MAX && dist[i] + graph[i][j] < dist[j]) {
                printf("\nContains negative cycle\n");
            }
        }
    }
    // Print the result: Vertex and its distance from the source
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}
int main() {
    int **graph = NULL;  // Adjacency matrix representation of the graph
    char choice = 'y', choice1 = 'y';
    int i, j, start = 0, end = 0;
    unsigned dist;
    V = 0;  // Initialize the number of vertices
    // Loop to input vertices and distances
    while (choice == 'y' || choice == 'Y') {
        // Allocate memory for the new graph with an additional vertex
        int **temp_graph = malloc((V + 1) * sizeof(int));
        if (temp_graph == NULL) {
            exit(1);
        }
        for (i = 0; i < V + 1; i++) {
            temp_graph[i] = malloc((V + 1) * sizeof(int));
            if (temp_graph[i] == NULL) {
                exit(1);
            }
        }
        // Copy the existing graph to the new graph
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                temp_graph[i][j] = graph[i][j];
            }
        }
        // Display the number of available vertices
        printf("Number of vertices available till now are %d\n", V + 1);
        V++;  // Increment the number of vertices
        // Initialize the new edges for the added vertex
        for (i = 0; i < V; i++) {
            temp_graph[V - 1][i] = 0;
            temp_graph[i][V - 1] = 0;
        }
        // Display the updated adjacency matrix
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                printf("%d ", temp_graph[i][j]);
            }
            printf("\n");
        }
        // Prompt for entering distances between vertices
        choice1 = 'y';
        while ((choice1 == 'y' || choice1 == 'Y') && V != 1) {
            do {
                printf("Enter the starting vertex index : ");
                scanf("%d", &start);
            } while (start > V);
            do {
                printf("Enter the ending vertex index : ");
                scanf("%d", &end);
            } while (end > V);
            printf("Enter distance between them : ");
            scanf("%u", &dist);
            temp_graph[start][end] = dist;
            printf("Do you want to enter new distance with current vertices (Y/N) : ");
            scanf("%s", &choice1);
        }
        // Update the graph with the new vertices and distances
        graph = temp_graph;
        // Display the updated adjacency matrix
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                printf("%d ", graph[i][j]);
            }
            printf("\n");
        }
        // Prompt for entering a new vertex
        printf("Do you want to enter new vertex (Y/N) : ");
        scanf("%s", &choice);
    }
    // Display the final adjacency matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    // Input the source node for the Bellman-Ford algorithm
    int source;
    printf("Enter the source node (0 to %d): ", V - 1);
    scanf("%d", &source);
    // Check if the source node is valid
    if (source < 0 || source >= V) {
        printf("Invalid source node. Please enter a valid source node (0 to %d).\n", V - 1);
        return 0;
    }
    // Perform the Bellman-Ford algorithm
    bellman(graph, source);
    return 0;
}
