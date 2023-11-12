#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform Insertion Sort on an array in ascending order
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to display elements of an array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Generate a random array of elements
    int arr[n];
    srand(time(NULL)); // Seed for the random number generator
    printf("Randomly Generated Array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform Insertion Sort
    insertionSort(arr, n);

    // Display the sorted array
    printf("Sorted array in ascending order: ");
    displayArray(arr, n);

    return 0;
}
