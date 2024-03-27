//Code by Kavya
#include<stdio.h>                               
int main(){
    int n, i, j, k, swap;  //Declaring variables                        
    printf("enter size of array ");
    scanf("%d", &n);                            
    int arr[n];//Declaring array                           
    printf("enter array ");                       
    for(i=0; i<n; i++){                                                        
        scanf("%d", &arr[i]);//Fetching its elements entered by the user              
    }
    printf("entered array before sorting  ");//Printing unsorted array
    for(i=0; i<n; i++){                          
        printf("%d ", arr[i]);               
    }
    printf("\n");
    for (i=0; i<n-1; i++){//Loop from 0 to n-1 called outer loop                   
        for(j=0; j<n-1-i; j++){ //Loop from 0 to n-1-i called inner loop so as to check each element except one sorted element      
            swap=0;//Defining variable swap to keep track of every iteration where elements have been swapped
            if(arr[j]>arr[j+1]){ //Checking if jth element is greater than j+1st element            
                int t=arr[j];//If condition satisfies swap them                  
                arr[j]=arr[j+1];                
                arr[j+1]=t;                     
                swap++;//Increasing swap with 1 with swapping
            }
            printf("pass %d, bubble %d : ", i+1, j+1);//Printing current ith index and buble operation wala index
            for(k=0; k<n; k++){
                printf("%d ", arr[k]);//Printing elements on each step
            }
            printf("\n");
        }
        if(swap==0){//If swap is 0 means printing i+1st index because of for loop swap will become 0 ultimaetly 
            printf("stopped at pass %d\n", i+1);
            break;
        }
    }
    printf("array after sorting : ");
    for(i=0; i<n; i++){                          
        printf("%d ", arr[i]);//Printing sorted array                  
    }
    return 0;                                   
}
