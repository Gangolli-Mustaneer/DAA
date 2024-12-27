#include <stdio.h>

int main() {
    float weight[50], profit[50], ratio[50], Totalvalue = 0, capacity;
    int n, i, j;

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input weight and profit for each item
    for (i = 0; i < n; i++) {
        printf("Enter Weight and Profit for item[%d]:\n", i);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    // Input capacity of knapsack
    printf("Enter the capacity of knapsack: ");
    scanf("%f", &capacity);

    // Calculate profit to weight ratio
    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items based on ratio in descending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratios
                float temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weights
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profits
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    // Greedy algorithm to calculate maximum value
    printf("Knapsack problems using Greedy Algorithm:\n");
    for (i = 0; i < n; i++) {
        if (weight[i] > capacity) {
            break; // Cannot include this item
        } else {
            Totalvalue += profit[i]; // Add full profit
            capacity -= weight[i]; // Reduce capacity
        }
    }

    // If there is remaining capacity, take the fraction of the next item
    if (i < n) {
        Totalvalue += (ratio[i] * capacity);
    }

    // Output the maximum value
    printf("\nThe maximum value is: %f\n", Totalvalue);
    return 0;
}