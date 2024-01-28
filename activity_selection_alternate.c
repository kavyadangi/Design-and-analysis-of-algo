//code by kavya
#include <stdio.h>
// Prints a maximum set of activities that can be done by a
// single person, one at a time.
void printMaxActivities(int s[], int f[], int n)
{
    int i, j;
    printf("Following activities are selected\n");
    i = 1; // the first activity always gets selected
    printf("%d ", i);
    for (j = 1; j < n; j++) {//taking rest of the activities
        if (s[j] >= f[i]) {// if this activity has start time grtr thn or equal to the finish time of previously selected activity, then select it
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

    int s[n]; // array to store start times
    int f[n]; // "            " finish times

    printf("Enter start and finish times for each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &s[i], &f[i]);
    }
    printMaxActivities(s, f, n);// function call
    return 0;
}
