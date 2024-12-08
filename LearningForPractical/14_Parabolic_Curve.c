#include<stdio.h>
#include<math.h>

int main() {
    int n;
    printf("Enter the number of terms you want: ");
    scanf("%d", &n);

    float x[n], y[n], xy[n], x2[n], x2y[n], x3[n], x4[n];
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumX2Y = 0, sumX3 = 0, sumX4 = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter x[%d]: ", i + 1);
        scanf("%f", &x[i]);
        printf("Enter y[%d]: ", i + 1);
        scanf("%f", &y[i]);
        xy[i] = x[i] * y[i];
        x2[i] = x[i] * x[i];
        x2y[i] = x2[i] * y[i];
        x3[i] = x[i] * x2[i];
        x4[i] = x2[i] * x2[i];
        sumX += x[i];
        sumY += y[i];
        sumXY += xy[i];
        sumX2 += x2[i];
        sumX2Y += x2y[i];
        sumX3 += x3[i];
        sumX4 += x4[i];
    }

    float matrix[3][4] = {
        {n, sumX, sumX2, sumY},
        {sumX, sumX2, sumX3, sumXY},
        {sumX2, sumX3, sumX4, sumX2Y}
    };

    for (int i = 0; i < 3; i++) {
        float diag = matrix[i][i];
        for (int j = 0; j < 4; j++) {
            matrix[i][j] /= diag;
        }
        for (int k = 0; k < 3; k++) {
            if (k != i) {
                float factor = matrix[k][i];
                for (int j = 0; j < 4; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }

    float a0 = matrix[0][3];
    float a1 = matrix[1][3];
    float a2 = matrix[2][3];

    printf("The coefficients are:\n");
    printf("a0 = %.2f\n", a0);
    printf("a1 = %.2f\n", a1);
    printf("a2 = %.2f\n", a2);

    return 0;
}
