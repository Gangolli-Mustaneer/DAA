#include <stdio.h>
#include <math.h>

int s[10][10], sol = 0;

void display(int m[], int n) {
    int i, j;
    for (i = 0; i < n; i++)
        s[i][m[i]] = 1; // Mark the position of the queen
    printf("Solution %d:\n", ++sol);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%3d", s[i][j]);
        printf("\n");
    }
    printf("\n");
    // Reset the board for the next solution
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            s[i][j] = 0;
}

int place(int m[], int k) {
    int i;
    for (i = 0; i < k; i++)
        if (m[i] == m[k] || abs(m[i] - m[k]) == abs(i - k))
            return 0; // Not a valid position
    return 1; // Valid position
}

int main() {
    int m[25], n, k;
    printf("Enter the number of Queens:\n");
    scanf("%d", &n);
    printf("\nThe solutions to the Queens problem are:\n");
    n--; // Adjust for zero-based indexing
    for (m[0] = 0, k = 0; k >= 0; m[k] += 1) {
        while (m[k] <= n && !place(m, k))
            m[k] += 1; // Find a valid position
        if (m[k] <= n) {
            if (k == n) {
                display(m, n + 1); // Display the solution
            } else {
                k++, m[k] = -1; // Move to the next queen
            }
        } else {
            k--; // Backtrack
        }
    }
    return 0; // Return success
}