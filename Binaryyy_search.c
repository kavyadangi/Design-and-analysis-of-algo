//code by kavya
#include <stdio.h>
int main(){
    int n, i, data, beg=0, mid,count=0;//defining variable
    printf("Enter max size of array");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        printf("Enter data");
        scanf("%d", &arr[i]);
    }
    printf("Enter data to be searched");//taking elemnt to srch
    scanf("%d", &data);
    int end=n-1;//defining end variable
    while(beg<=end){//we will continue srch till this condition
        count++;//keeping count of srches
        mid=(beg+end)/2;//defining mid = middle of the list 
        if(arr[mid]==data){//if elemnt vfound at mid then print found 
            printf("%d found at location %d", data, mid+1);
            break;
        }
        else if(arr[mid]<data){//if not found at mid check for its left right by dividing into two prts
            beg=mid+1;
        }
        else if(arr[mid]>data){
            end=mid-1;
        }
        else{
            printf("not found");
        }
       
    }
     printf("\n%d number of times srching is dn\n",count);
    return 0;
}