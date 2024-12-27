#include <stdio.h>

// Global variables to store maximum and minimum values
int max, min;
int a[100];

// Function to find maximum and minimum values in the array
void maxmin(int i, int j) {
    int max1, min1, mid;
    if (i == j) {
        max = min = a[i];
    } else {
        if (i == j - 1) {
            if (a[i] < a[j]) {
                max = a[j];
                min = a[i];
            } else {
                max = a[i];
                min = a[j];
            }
        } else {
            mid = (i + j) / 2;
            maxmin(i, mid);
            max1 = max; 
            min1 = min;
            maxmin(mid + 1, j);
            if (max < max1) max = max1;
            if (min > min1) min = min1;
        }
    }
}

int main() {
    int i, num;

    // Prompt user for the number of elements
    printf("Enter the total number of numbers: ");
    scanf("%d", &num);

    // Prompt user for the numbers
    printf("Enter the numbers:\n");
    for (i = 0; i < num; i++) {
        scanf("%d", &a[i]); // Changed to start from index 0
    }

    // Call the maxmin function
    maxmin(0, num - 1); // Changed to pass 0 and num - 1

    // Print the results
    printf("Minimum element in the array: %d\n", min);
    printf("Maximum element in the array: %d\n", max);

    return 0; // Return statement for main
}