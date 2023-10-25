#include <stdio.h>

// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;

    printf("Following activities are selected\n");

    // The first activity always gets selected
    i = 1;
    printf("%d ", i);

    // Consider rest of the activities
    for (j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (s[j] >= f[i]) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    int s[n]; // Array to store start times
    int f[n]; // Array to store finish times

    printf("Enter start and finish times for each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &s[i], &f[i]);
    }

    // Function call
    printMaxActivities(s, f, n);
    return 0;
}
