#include<stdio.h>
int main(){
    int n,i,flag=0;
    printf("enter no");
    scanf("%d",&n);
    if(n==0 || n==1){
        printf("The number is neither prime nor composite");
    }
    for(i=2;i<n/2;i++){
        if(n%i==0){
            flag=1;
        }
    }
    if(flag==1){
        printf("%d is a composite number",n);
    }
    else{
        printf("%d is a prime number",n);
    }
    return 0;
}