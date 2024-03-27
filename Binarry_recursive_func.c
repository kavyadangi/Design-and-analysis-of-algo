//code by kavya
#include <stdio.h>
int count=0;                                               
int recursivebinary(int arr[], int beg, int end, int data){             
    int mid;                                               
    while(beg<=end){   //same as binary srch in this we are claling function recursively                                   
        count++;                                          
        if(beg==end){                                     
            if(arr[beg]==data){
                return beg;
            }
            else{
                return -1;
            }
        }
        else{                                             
            mid=(beg+end)/2;                               
            if(arr[mid]==data){                         
                return mid;
            }
            else if(arr[mid]>data){        
                return recursivebinary(arr, beg, mid-1, data);
            }
            else{                                          
                return recursivebinary(arr, mid+1, end, data);
            }
        }
    }
    if(end<beg){
        printf("element not found");
    }
}
int main(){
    int i, n, data, beg=0;                               
    printf("enter size of array");
    scanf("%d", &n);                                     
    int arr[n], end=n-1;
    for(i=0; i<n; i++){                                
        scanf("%d", &arr[i]);
    }
    printf("enter data to be searched");          
    scanf("%d", &data);
    printf("%d found at location %d", data, recursivebinary(arr, beg, end, data));  //calling func recursively on the basis of srch
    printf("\nnumber of times searching done is %d", count);  
    return 0;
}

