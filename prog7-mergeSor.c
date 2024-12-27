#include <stdio.h>

int i, j, k, a[20];

void mergesort(int, int);
void merge(int, int, int);

int main() {
    int n;
    printf("Enter the size of an array:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) // Changed to start from 0
        scanf("%d", &a[i]);
    
    mergesort(0, n - 1); // Changed to start from 0 and end at n-1
    printf("Sorted array is:\n");
    for (i = 0; i < n; i++) // Changed to start from 0
        printf("%d\n", a[i]);
    
    return 0; // Added return statement
}

void mergesort(int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high) {
    int b[20]; // Ensure this is large enough for the merge
    int h = low, i = low, j = mid + 1;

    while ((h <= mid) && (j <= high)) {
        if (a[h] < a[j]) {
            b[i++] = a[h];
            h++;
        } else {
            b[i++] = a[j];
            j++;
        }
    }
    
    if (h > mid) {
        for (k = j; k <= high; k++)
            b[i++] = a[k];
    } else {
        for (k = h; k <= mid; k++)
            b[i++] = a[k];
    }
    
    for (k = low; k <= high; k++)
        a[k] = b[k];
}