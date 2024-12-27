#include <stdio.h>
#define TRUE 1
#define FALSE 0

int inc[50], w[50], sum, n;

int promising(int i, int wt, int total) {
    return (((wt + total) >= sum) && ((wt == sum) || (i + 1 < n && wt + w[i + 1] <= sum)));
}

void sumset(int i, int wt, int total);

int main() {  // Changed void to int
    int i, j, temp, total = 0;
    printf("Enter how many numbers:\n");
    scanf("%d", &n);
    
    // Check for valid input
    if (n > 50) {
        printf("Error: Maximum number of elements is 50.\n");
        return 1; // Exit with error
    }

    printf("\nEnter %d numbers to the set:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        total += w[i];
    }
    printf("\nInput the sum value to create subset:\n");
    scanf("%d", &sum);
    
    // Sorting the array using bubble sort
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1; j++) {
            if (w[j] > w[j + 1]) {
                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;
            }
        }
    }
    
    if (total < sum) {
        printf("\nSubset construction is not possible\n");
    } else {
        for (i = 0; i < n; i++)
            inc[i] = 0;
        printf("\nThe solution using backtracking is:\n");
        sumset(-1, 0, total);
    }
    return 0; // Return success
}

void sumset(int i, int wt, int total) {
    int j;
    if (promising(i, wt, total)) {
        if (wt == sum) {
            printf("\n{\t");
            for (j = 0; j <= i; j++)
                if (inc[j])
                    printf("%d\t", w[j]);
            printf("}\n");
        } else {
            inc[i + 1] = TRUE;
            sumset(i + 1, wt + w[i + 1], total - w[i + 1]);
            inc[i + 1] = FALSE;
            sumset(i + 1, wt, total - w[i + 1]);
        }
    }
}