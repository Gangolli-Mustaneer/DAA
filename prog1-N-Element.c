#include <stdio.h>
#include<stdlib.h>
void selectionSort(int arr[], int n)
{
    int i, j, min_idx, temp;
    // One by one move boundary of unsorted subarray  	
    for (i = 0; i < n - 1; i++) {
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i + 1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

    // Swap the found minimum element with the first element
    temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
}
}

int main()
{
    int arr[100], i, n;
    printf("enter the size of an Array\n");
    scanf("%d", &n);
    printf("Enter the %d Array Elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
