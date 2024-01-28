//code by ktg
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
int minDist(int dist[], bool Visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!Visited[v] && min >= dist[v]) {//checkoing whether the vertex is vissited or not
            min = dist[v];
            min_index = v;
        };
    }
    return min_index;//returning visited vertex's index
}
void prifinalre(int dist[], int n) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < n; i++) {
         printf("%d \t%d\n", i, dist[i]);
    }
}
void bellmanFord(int V, int graph[V][V], int src) {
    int dist[V];
    bool Visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        Visited[i] = false;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        for (int u = 0; u < V; u++) {
            if (dist[u] != INT_MAX) {
                for (int v = 0; v < V; v++) {
                    if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
        }
    }
    // Check for negative weight cycles
    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                printf("Graph contains negative weight cycle\n");
                return;
            }
        }
    }
    prifinalre(dist, V);
}
int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int graph[V][V];
    printf("Enter the graph as an adjacency matrix where self loops are not being counted, so it should be 0:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int source;
    printf("Enter the source node (0 to %d): ", V - 1);
    scanf("%d", &source);

    if (source < 0 || source >= V) {
        printf("Invalid source node. Please enter a valid source node (0 to %d).\n", V - 1);
        return 0;
    }
    bellmanFord(V, graph, source);
    return 0;
}
