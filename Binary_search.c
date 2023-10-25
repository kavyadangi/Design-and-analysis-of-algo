#include<stdio.h>
int main(){
    int n,i,num,beg,end,mid;
    printf("enter number of elemnts");
    scanf("%d",&n);
    int arr[n];
    printf("enter elemnts");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter number to be srched");
    scanf("%d",&num);
    beg=0;
    end=n-1;
    while(beg<=end){
         mid=(beg+end)/2;
        if(num==mid){
            printf("number found at %d",mid);
            break;
        }
        else if(num<arr[mid]){
            end=mid-1;
            
        }
        else if(num>arr[mid]){
            beg=mid+1;
        
        }
    }
   

    return 0;
}