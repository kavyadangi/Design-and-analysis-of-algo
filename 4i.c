#include <stdio.h>
#include <stdlib.h>


// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        // Print the element being sorted in each step
        printf("Sorting element %d: ", key);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the number of elements in the array: "); // Prompt the user for 'n'
    scanf("%d", &n); // Read the value of 'n' from the user

    int arr[n]; // Declare an integer array of size 'n'

    // Seed the random number generator with the current time
   // srand(time(NULL));

    printf("Original array (n = %d):\n", n); // Display the number of elements
    for (int i = 0; i < n; i++) {
        arr[i] = rand()%100; // Generate random elements and store them in the array
        printf("%d ", arr[i]); // Display the generated element
    }
    printf("\n");

    insertionSort(arr, n); // Call the insertionSort function to sort the array

    printf("Sorted array (n = %d):\n", n); // Display the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Display the sorted element
    }
    printf("\n");

    return 0;
}
