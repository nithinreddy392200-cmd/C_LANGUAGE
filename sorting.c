#include <stdio.h>
#include <stdlib.h>

// Function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort function
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Function to display array
void displayArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i, choice;

    printf("=== Sorting Program (Bubble Sort) ===\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    displayArray(arr, n);

    printf("\nChoose Sorting Order:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    bubbleSort(arr, n);

    if (choice == 1) {
        printf("\nSorted Array (Ascending): ");
        displayArray(arr, n);
    } else if (choice == 2) {
        printf("\nSorted Array (Descending): ");
        for (i = n-1; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("\nInvalid choice! Showing ascending order by default:\n");
        displayArray(arr, n);
    }

    printf("\n=== Program Finished ===\n");
    return 0;
}