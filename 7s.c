#include <stdio.h>

// Function to perform Strassen's matrix multiplication for '4 x 4' matrices
void strassenMatrixMultiplication(int A[4][4], int B[4][4], int C[4][4]) {
    // Divide matrices into submatrices
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2];
    int M6[2][2], M7[2][2];
    int temp1[2][2], temp2[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // Divide matrices into submatrices
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + 2];
            A21[i][j] = A[i + 2][j];
            A22[i][j] = A[i + 2][j + 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + 2];
            B21[i][j] = B[i + 2][j];
            B22[i][j] = B[i + 2][j + 2];
        }
    }

    // Compute M1 to M7
    // ...

    // Compute C submatrices
    // ...

    // Copy submatrices into the result matrix
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = C11[i][j];
            C[i][j + 2] = C12[i][j];
            C[i + 2][j] = C21[i][j];
            C[i + 2][j + 2] = C22[i][j];
        }
    }
}

int main() {
    int A[4][4], B[4][4], C[4][4];

    // Read user input for matrix A
    printf("Enter matrix A (4 x 4 elements, row by row):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read user input for matrix B
    printf("Enter matrix B (4 x 4 elements, row by row):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform Strassen's matrix multiplication
    strassenMatrixMultiplication(A, B, C);

    // Display the result
    printf("Strassen's Matrix Multiplication Result:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
