//Code by Kavya
#include <stdio.h>
#define MAX_SIZE 100
void countSort(int arr[], int n) {
    int max = 0;
    // Find the maximum element in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    // Create a count array to store the count of each element
    int count[MAX_SIZE] = {0};
    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // Update count array to store the actual position of each element
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    // Create the output array
    int output[MAX_SIZE];
    // Build the output array using the count array
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int n;
    // Input the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[MAX_SIZE];
    // Input elements of the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Original array: ");
    printArray(arr, n);
    countSort(arr, n);
    printf("Sorted array: ");
    printArray(arr, n);
    return 0;
}
