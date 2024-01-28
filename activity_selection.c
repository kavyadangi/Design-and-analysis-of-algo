#include <stdio.h>
#include <stdlib.h>
struct Activity {
    int start, finish;
};
int compareActivities(const void *a, const void *b) {//using dynamic memory alloction for comparing activties so as to put in ready queue
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}
void activitySelection(struct Activity activities[], int n) {
    qsort(activities, n, sizeof(struct Activity), compareActivities);

    printf("Selected activities:\n");
    int i = 1;
    
    printf("Activity %d: (%d, %d)\n", i+1 , activities[i].start, activities[i].finish);

    for (int j = 1; j < n; j++) {
        if (activities[j].start >= activities[i].finish) {
            printf("Activity %d: (%d, %d)\n", j+2, activities[j].start, activities[j].finish);
            i = j;
        }
    }
}
int main() {
    int n;

    printf("Enter the number of activities: ");
    scanf("%d", &n);
    struct Activity activities[n]; // fixed-size array
    printf("Enter start and finish times for each activity:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }
    activitySelection(activities, n);
    return 0;
}