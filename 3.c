#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for rand() and srand()
#include <time.h>   // Include time.h for seeding the random number generator

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() {
    int arr[10];

    // Seed the random number generator with the current time
    //srand(time(NULL));

    printf("Original array:\n");
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100; // Generate random integers between 0 and 99
        printf("%d\n", arr[i]);
    }

    quicksort(arr, 0, 9);

    printf("Sorted array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

void quicksort(int arr[], int l, int h) {
    if (l < h) {
        int j = partition(arr, l, h);
        quicksort(arr, l, j - 1);
        quicksort(arr, j + 1, h);
    }
}

int partition(int arr[], int l, int h) {
    int pivot, p, q;
    p = l;
    q = h + 1;
    pivot = arr[l];

    while (1) {
        do {
            p++;
        } while (arr[p] < pivot);
        do {
            q--;
        } while (arr[q] > pivot);
        if (p < q) {
            int t = arr[p];
            arr[p] = arr[q];
            arr[q] = t;
        } else {
            break;
        }
    }

    arr[l] = arr[q];
    arr[q] = pivot;

    return q;
}
