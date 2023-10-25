#include <stdio.h>

int partition(int arr[], int beg, int end);
void quicksort(int arr[], int beg, int end);

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    quicksort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

int partition(int arr[], int beg, int end) {
    int pivot = arr[beg]; // Select the pivot element as the first element
    printf("\nPivot: %d\n", pivot);
    int p = beg, q = end, t;

    while (p < q) {
        while (arr[p] <= pivot) {
            p++;
        }
        while (arr[q] > pivot) {
            q--;
        }
        if (p < q) {
            t = arr[p];
            arr[p] = arr[q];
            arr[q] = t;
        }

        printf("p: %d, q: %d\n");

        printf("Array after partition: ");
        for (int i = beg; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n\n");
    }

    arr[beg] = arr[q];
    arr[q] = pivot;

    return q;
}

void quicksort(int arr[], int beg, int end) {
    int loc;
    if (beg < end) {
        loc = partition(arr, beg, end);
        printf("Left: Sorting elements from index %d to %d\n", beg, loc - 1);
        quicksort(arr, beg, loc - 1);
        printf("Right: Sorting elements from index %d to %d\n", loc + 1, end);
        quicksort(arr, loc + 1, end);
    }
}
