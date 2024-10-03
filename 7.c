///Gauss Elimination Method
#include <stdio.h>
#include <math.h>


void gaussElimination(float A[20][20], int n, float x[10]) {
    int i, j, k;
    float c, sum;
    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (i > j) {
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++) {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }
    x[n] = A[n][n + 1] / A[n][n];
    for (i = n - 1; i >= 1; i--) {
        sum = 0;
        for (j = i + 1; j <= n; j++) {
            sum = sum + A[i][j] * x[j];
        }
        x[i] = (A[i][n + 1] - sum) / A[i][i];
    }
}

int main() {
    int i,j,m,n;
    float x[10];
    printf("Enter row and column of matrix: ");
    scanf("%d",&n);
    float A[m][n];
    printf("Enter the elements of augmented matrix row-wise:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            printf("A[%d][%d] : ", i-1, j)-1;
            scanf("%f", &A[i][j]);
        }
    }
    gaussElimination(A, n, x);
    printf("\nThe solution is: \n");
    for (i = 1; i <= n; i++) {
        printf("\nx%d = %f", i, x[i]);
    }
    return 0;
}
