#include <stdio.h>
#include <conio.h>

void quicksortMiddle(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[(low + high) / 2]; // Selecting the middle element as the pivot
        int i = low;
        int j = high;
        int temp;

        while (i <= j) {
            while (arr[i] < pivot) 
                i++; // Moving elements smaller than pivot to the left
            while (arr[j] > pivot) 
                j--; // Moving elements greater than pivot to the right
            
            if (i <= j) {
                // Swapping elements
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        // Recursively sort the two partitions
        if (low < j) quicksortMiddle(arr, low, j);
        if (i < high) quicksortMiddle(arr, i, high);
    }
}

int main() {
    int arr[100], i, n;

    // Clear the screen (Note: clrscr() is not standard and may not work in all compilers)
    // clrscr(); // Uncomment if your compiler supports it

    printf("Enter the size of the Array (max 100):\n");
    scanf("%d", &n);

    if (n > 100 || n <= 0) {
        printf("Invalid size. Please enter a number between 1 and 100.\n");
        return 1; // Exit the program with an error code
    }

    printf("Enter the %d Array Elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Using the Middle Element as Pivot
    quicksortMiddle(arr, 0, n - 1);

    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Wait for a key press (Note: getch() is not standard and may not work in all compilers)
    // getch(); // Uncomment if your compiler supports it

    return 0; // Return success
}