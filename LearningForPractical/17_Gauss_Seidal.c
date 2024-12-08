#include<stdio.h>
#include<math.h>

int main() {
    int n;
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    float arr[n][n+1];  // Coefficients and constants matrix
    float values[n];     // Solution values

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n+1; j++) {
            scanf("%f", &arr[i][j]);
        }
    }

    // Initialize the solution values (can be zeros or guesses)
    for(int i = 0; i < n; i++) {
        values[i] = 0.0;  // You can also start with an initial guess, like 1.0
    }

    // Gauss-Seidel iteration
    int max_iter = 100;  // Maximum number of iterations
    float tolerance = 0.0001;  // Convergence tolerance
    for(int iter = 0; iter < max_iter; iter++) {
        float error = 0.0;
        
        for(int i = 0; i < n; i++) {
            float sum = arr[i][n];  // Start with the constant term

            // Calculate the sum for the current row using the updated values
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    sum -= arr[i][j] * values[j];
                }
            }

            // Update the solution for the current variable
            float new_value = sum / arr[i][i];
            error = fmax(error, fabs(values[i] - new_value));  // Track maximum error

            values[i] = new_value;  // Set the updated value
        }

        // Check for convergence (if error is less than tolerance)
        if(error < tolerance) {
            printf("Converged after %d iterations.\n", iter + 1);
            break;
        }
    }

    // Output the solution
    printf("Values of unknowns are:\n");
    for(int i = 0; i < n; i++) {
        printf("x%d = %f\n", i+1, values[i]);
    }

    return 0;
}
