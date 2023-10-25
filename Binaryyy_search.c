#include <stdio.h>
int main(){
    int n, i, data, beg=0, mid;
    printf("Enter max size of array");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        printf("Enter data");
        scanf("%d", &arr[i]);
    }
    printf("Enter data to be searched");
    scanf("%d", &data);
    int end=n-1;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==data){
            printf("%d found at location %d", data, mid+1);
            break;
        }
        else if(arr[mid]<data){
            beg=mid+1;
        }
        else if(arr[mid]>data){
            end=mid-1;
        }
    }
    return 0;
}