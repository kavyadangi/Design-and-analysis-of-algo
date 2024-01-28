#include <stdio.h>

char A[] = "ACXYFLMN\n";
char B[] = "ANXYFML\n";

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS(int i, int j) {
    if (A[i] == '\n' || B[j] == '\n') {
        return 0;
    } else if (A[i] == B[j]) {
        return 1 + LCS(i + 1, j + 1);
    } else {
         return max(LCS(i + 1, j), LCS(i, j + 1));
    }
}

int main() {
    int result = LCS(0, 0);
    printf("Length of LCS is %d\n", result);
    return 0;
}