#include<stdio.h>
int main(){
    int n;
    printf("Enter no of elemetns");
    scanf("%d",&n);
    int arr[n],i,num,found=1;
    
   for(i=0;i<n;i++){
        printf("enter elemnets");
        scanf("%d",&arr[i]);
    }
    printf("enter number to be searched");
    scanf("%d",&num);
    for(i=0;i<n;i++){
        if (arr[i]==num){
            found=0;
            printf("found %d at position at %d",num,i+1);
            break;
        }
    
    }
    if(found==1){
        printf("%d not found",num);
    }
      return 0;

    }
  
