#include <stdio.h>
#include <math.h>

// Function to convert the augmented matrix to diagonal form
void convertToDiagonal(float a[][100], int n) {
    int i, j, k, x, y;
    float ratio;

    for (i = 0; i < n; i++) {
        // Check for zero pivot element
        if (fabs(a[i][i]) < 1e-6) {
            printf("Error: Zero pivot encountered. Unable to proceed.\n");
            return;
        }

        for (j = 0; j < n; j++) {
            if (j != i) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++) {
                    a[j][k] -= ratio * a[i][k];
                }

                // Print intermediate forms of the matrix
                printf("Intermediate forms:\n");
                for (x = 0; x < n; x++) {
                    for (y = 0; y < n + 1; y++) {
                        printf("%8.3f ", a[x][y]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
    }
}

// Function to print the values of the unknowns
void printUnknowns(float a[][100], int n) {
    int i;
    printf("Values of unknowns are:\n");
    for (i = 0; i < n; i++) {
        printf("Value of Variable %d = %.3f\n", i + 1, a[i][n] / a[i][i]);
    }
}

int main() {
    int n, i, j;
    float a[100][100];

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    convertToDiagonal(a, n);
    printUnknowns(a, n);

    return 0;
}
