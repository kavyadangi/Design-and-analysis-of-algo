#include<stdio.h>
int main(){
    int A[2][2],B[2][2],C[2][2],i,j;
    printf("enter elemnts of first matrix");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
        scanf("%d",&A[i][j]);
    }
}
printf("enter elemnts of second matrix");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
        scanf("%d",&B[i][j]);
    }
}
C[0][0]=(A[0][0] *B[0][0])+(A[0][1]*B[1][0]);
C[0][1]=(A[0][0] *B[0][1])+(A[0][1]*B[1][1]);
C[1][0]=(A[1][0] *B[0][0])+(A[1][1]*B[1][0]);
C[1][1]=(A[1][0] *B[0][1])+(A[1][1]*B[1][1]);
for(i=0;i<2;i++){
    printf("\n");
    for(j=0;j<2;j++){
        printf("%d\t",C[i][j]);
    }
}
return 0;
}
