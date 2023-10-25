#include <stdio.h>

// Function to add two matrices
void add(int A[][100], int B[][100], int C[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

// Function to subtract two matrices
void subtract(int A[][100], int B[][100], int C[][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

// Function to perform Strassen's matrix multiplication for 'n x n' matrices
void strassenMatrixMultiplication(int A[][100], int B[][100], int C[][100], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Divide matrices into submatrices
    int newSize = n / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize], M5[newSize][newSize];
    int M6[newSize][newSize], M7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Compute M1 to M7
    add(A11, A22, temp1, newSize);
    add(B11, B22, temp2, newSize);
    strassenMatrixMultiplication(temp1, temp2, M1, newSize);

    add(A21, A22, temp1, newSize);
    strassenMatrixMultiplication(temp1, B11, M2, newSize);

    subtract(B12, B22, temp2, newSize);
    strassenMatrixMultiplication(A11, temp2, M3, newSize);

    subtract(B21, B11, temp2, newSize);
    strassenMatrixMultiplication(A22, temp2, M4, newSize);

    add(A11, A12, temp1, newSize);
    strassenMatrixMultiplication(temp1, B22, M5, newSize);

    subtract(A21, A11, temp1, newSize);
    add(B11, B12, temp2, newSize);
    strassenMatrixMultiplication(temp1, temp2, M6, newSize);

    subtract(A12, A22, temp1, newSize);
    add(B21, B22, temp2, newSize);
    strassenMatrixMultiplication(temp1, temp2, M7, newSize);

    // Compute C submatrices
    add(M1, M4, temp1, newSize);
    subtract(M7, M5, temp2, newSize);
    add(temp1, temp2, C11, newSize);

    add(M3, M5, C12, newSize);

    add(M2, M4, C21, newSize);

    subtract(M1, M2, temp1, newSize);
    add(M3, M6, temp2, newSize);
    add(temp1, temp2, C22, newSize);

    // Copy submatrices into the result matrix
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter the value of n (matrix size 'n x n'): ");
    scanf("%d", &n);

    int A[100][100], B[100][100];
    int C_strassen[100][100];

    // Read user input for matrix A
    printf("Enter matrix A (%d x %d elements, row by row):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Read user input for matrix B
    printf("Enter matrix B (%d x %d elements, row by row):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Perform Strassen's matrix multiplication
    strassenMatrixMultiplication(A, B, C_strassen, n);

    // Display the result
    printf("Strassen's Matrix Multiplication Result:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", C_strassen[i][j]);
        }
        printf("\n");
    }

    return 0;
}
