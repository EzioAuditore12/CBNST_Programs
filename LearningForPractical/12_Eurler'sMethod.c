#include<stdio.h>

// Differential equation function
float function(float x, float y) {
    return (y - x) / (y + x);
}

int main() {
    float x0, y0, x, h;
    
    // Taking input from the user
    printf("Enter x0, y0, x, and h: ");
    scanf("%f %f %f %f", &x0, &y0, &x, &h);  

    // Calculate number of steps
    int n = (int)((x - x0) / h); 
    printf("Number of steps = %d\n", n);

    float y = y0;  // Initialize y with the initial value y0

    // Iterate from x0 to x, updating y using Euler's method
    while (x0 < x) {
        y = y + h * function(x0, y);  // Update y using Euler's method
        x0 = x0 + h;  // Increment x0 by the step size h
    }

    // Output the result
    printf("Value of y at x = %.4f is %.4f\n", x, y);  
    return 0;
}
