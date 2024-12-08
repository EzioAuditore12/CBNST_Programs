#include <stdio.h>

// Define the function f(x, y) = (y^2 - x^2) / (y^2 + x^2)
float function(float x, float y) {
    return (y * y - x * x) / (y * y + x * x);
}

int main() {
    float x0, y0, x, y, h;
    int n;

    // Input initial values: x0, y0, the point to calculate y, and step size (h)
    printf("Enter the initial values of x0 and y0: ");
    scanf("%f %f", &x0, &y0);

    printf("Enter the value of x at which you want to calculate y: ");
    scanf("%f", &x);

    printf("Enter the step size (h): ");
    scanf("%f", &h);

    // Calculate the number of steps required
    n = (int)((x - x0) / h);

    printf("Number of steps = %d\n", n);

    // Initialize the starting values
    y = y0;
    float xi = x0;

    // Perform Runge-Kutta method
    for (int i = 0; i < n; i++) {
        float k1 = h * function(xi, y);
        float k2 = h * function(xi + h / 2, y + k1 / 2);
        float k3 = h * function(xi + h / 2, y + k2 / 2);
        float k4 = h * function(xi + h, y + k3);

        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;  // Update y
        xi = xi + h;  // Update x

        // Print the results for each step
        printf("Step %d: x = %.4f, y = %.4f\n", i + 1, xi, y);
    }

    // Final result
    printf("Value of y at x = %.4f is %.4f\n", x, y);

    return 0;
}
