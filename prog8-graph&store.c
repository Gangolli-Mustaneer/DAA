#include <stdio.h>
#define MAX_VERTICES 10

int main() {
    int vertices, edges;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Input the number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Ensure the number of vertices is within the allowed limit
    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Exiting...\n");
        return 1;
    }

    // Ensure the number of edges is non-negative
    if (edges < 0) {
        printf("Invalid number of edges. Exiting...\n");
        return 1;
    }

    // Adjacency matrix to store the graph
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};

    // Input edges and populate the adjacency matrix
    for (int i = 0; i < edges; i++) {
        int startVertex, endVertex;

        // Input the edge vertices
        printf("Enter edge #%d (startVertex endVertex): ", i + 1);
        scanf("%d %d", &startVertex, &endVertex);

        // Validate vertex inputs
        if (startVertex < 1 || startVertex > vertices || endVertex < 1 || endVertex > vertices) {
            printf("Invalid vertex input. Exiting...\n");
            return 1;
        }

        // Check for duplicate edges
        if (adjacencyMatrix[startVertex - 1][endVertex - 1] == 1) {
            printf("Duplicate edge detected. Exiting...\n");
            return 1;
        }

        // Update the adjacency matrix
        adjacencyMatrix[startVertex - 1][endVertex - 1] = 1;
        adjacencyMatrix[endVertex - 1][startVertex - 1] = 1; // For undirected graph
    }

    // Display the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}