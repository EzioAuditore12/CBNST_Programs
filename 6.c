#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define EPSILON 0.0009

// Function whose root is to be found
float findValueAt(float x) {
    return x*x*x - 4*x - 9;  // f(x) = x^3 - 4x - 9
}

// Secant method formula to find the new approximation
float findX(float x1, float x2) {
    return x2 - ((x1 - x2) / (findValueAt(x2) - findValueAt(x1))) * findValueAt(x2);
}

int main() {
    int maxIteration, i = 1;
    float x1, x2, x;

    // Taking input from the user
    printf("Enter x1 and x2\n");
    scanf("%f %f", &x1, &x2);

    printf("Enter Maximum no of Iterations\n");
    scanf("%d", &maxIteration);

    // Check if initial guesses are valid (root is bracketed)
    if (findValueAt(x1) * findValueAt(x2) < 0) {
        // Iterate until max iterations or desired precision
        while (i <= maxIteration) {
            x = findX(x1, x2);
            printf("Iteration = %d, Approximate Root = %f\n", i, x);

            // Check if convergence is achieved
            if (fabs(x - x2) < EPSILON) {
                printf("Converged to root = %f after %d iterations.\n", x, i);
                break;
            }

            // Prepare for next iteration
            x1 = x2;
            x2 = x;
            i++;
        }

        // If maximum iterations are reached without convergence
        if (i > maxIteration) {
            printf("Maximum iterations reached. Approximate root = %f\n", x);
        }
    } else {
        // If initial guesses do not bracket a root
        printf("Invalid initial guesses. The function values must have opposite signs.\n");
        exit(0);
    }

    return 0;
}
