#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    if (n <= 1) {
        printf("Error: At least two data points are required for regression.\n");
        return 1;
    }

    double x[n], y[n];
    printf("Enter the values of X and Y (space-separated):\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x[i], &y[i]);
    }

    // Variables to store sums
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0, sumY2 = 0;

    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
        sumY2 += y[i] * y[i];
    }

    // Regression line Y on X
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX); // Slope for Y on X
    double a = (sumY - b * sumX) / n; // Intercept for Y on X

    // Regression line X on Y
    double d = (n * sumXY - sumX * sumY) / (n * sumY2 - sumY * sumY); // Slope for X on Y
    double c = (sumX - d * sumY) / n; // Intercept for X on Y

    printf("\nRegression Line of Y on X: Y = %.4lf + %.4lfX\n", a, b);
    printf("Regression Line of X on Y: X = %.4lf + %.4lfY\n", c, d);

    return 0;
}
