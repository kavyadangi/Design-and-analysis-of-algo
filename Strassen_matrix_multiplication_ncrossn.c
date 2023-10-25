#include<stdio.h>
int n;
void SMM(int[n][n],int[n][n],int);
int main(){
    int i,j;
    printf("enter order");
    scanf("%d",&n);
    int A[n][n], B[n][n],C[n][n];
    printf("enter elemnts of first matrix");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("enter elemnts of second matrix");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&B[i][j]);
        }
    }  
    SMM(A[n][n],B[n][n],n);
    void SMM(int A[][],int B[][],int n){
        C[0][0]=(A[0][0] *B[0][0])+(A[0][1]*B[1][0]);
        C[0][1]=(A[0][0] *B[0][1])+(A[0][1]*B[1][1]);
        C[1][0]=(A[1][0] *B[0][0])+(A[1][1]*B[1][0]);
        C[1][1]=(A[1][0] *B[0][1])+(A[1][1]*B[1][1]);


    }
    for(i=0;i<2;i++){
    printf("\n");
    for(j=0;j<2;j++){
        printf("%d\t",C[i][j]);
    }
}
return 0;
    
}
