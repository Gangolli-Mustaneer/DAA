#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // Maximum number of vertices

void print_indegree_outdegree(int adj_matrix[][MAX_VERTICES], int num_vertices) {
    int in_degree[MAX_VERTICES], out_degree[MAX_VERTICES];

    // Initialize In-Degree and Out-Degree for each vertex
    for (int i = 0; i < num_vertices; i++) {
        in_degree[i] = 0;
        out_degree[i] = 0;

        // Calculate In-Degree and Out-Degree
        for (int j = 0; j < num_vertices; j++) {
            in_degree[i] += adj_matrix[j][i]; // Sum incoming edges
            out_degree[i] += adj_matrix[i][j]; // Sum outgoing edges
        }
    }

    // Print the In-Degree and Out-Degree for each vertex
    for (int i = 0; i < num_vertices; i++) {
        printf("Vertex %d: In-Degree: %d, Out-Degree: %d\n", i + 1, in_degree[i], out_degree[i]);
    }

    // Print the adjacency matrix
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int num_vertices;

    // Input number of vertices with validation
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &num_vertices);
    if (num_vertices <= 0 || num_vertices > MAX_VERTICES) {
        printf("Invalid number of vertices. Please enter a value between 1 and %d.\n", MAX_VERTICES);
        return 1; // Exit with error
    }

    int adj_matrix[MAX_VERTICES][MAX_VERTICES];

    // Input adjacency matrix with validation
    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            scanf("%d", &adj_matrix[i][j]);
            // Validate input for adjacency matrix
            if (adj_matrix[i][j] != 0 && adj_matrix[i][j] != 1) {
                printf("Invalid input. Please enter 0 or 1.\n");
                return 1; // Exit with error
            }
        }
    }

    print_indegree_outdegree(adj_matrix, num_vertices);
    return 0;
}