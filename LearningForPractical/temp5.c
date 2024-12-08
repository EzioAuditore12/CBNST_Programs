#include <stdio.h>
#include <math.h>

// Function to evaluate
float f(float x) {
    return (1 / (1 + (x * x)));
}

// Simpson's 1/3 Rule
float simpson_1by3(float y[], int n, float h) {
    int i;
    float sum = 0;
    for (i = 1; i < n - 1; i++) {
        if (i % 2 == 0) {
            sum += 2 * y[i]; // 2*(Y2+Y4+Y6...)
        } else {
            sum += 4 * y[i]; // 4*(Y1+Y3+Y5...)
        }
    }
    sum = (h * (y[0] + y[n - 1] + sum)) / 3.0;
    return sum;
}

// Simpson's 3/8 Rule
float simpson_3by8(float y[], int l, int n, float h) {
    int i;
    float sum = 0.0;
    for (i = l + 1; i < n - 1; i++) {
        if ((i - l) % 3 == 0) {
            sum += 2 * y[i]; // 2*(Y3+Y6+...)
        } else {
            sum += 3 * y[i]; // 3*(Y1+Y2+Y4+Y5+...)
        }
    }
    sum = (3 * h * (y[l] + y[n - 1] + sum)) / 8.0;
    return sum;
}

int main() {
    int i, n;
    float u, l, h, I;
    
    // Input limits and interval size
    printf("Enter Upper limit: ");
    scanf("%f", &u);
    printf("Enter lower limit: ");
    scanf("%f", &l);
    printf("Enter interval size: ");
    scanf("%f", &h);
    
    // Calculate the number of intervals
    n = (int)((u - l) / h) + 1; // Total points
    
    // Arrays to store x and y values
    float x[n], y[n];
    
    // Calculate x and y values
    for (i = 0; i < n; i++) {
        x[i] = l + i * h;  // Xn = X0 + nh
        y[i] = f(x[i]);    // y = f(x)
    }
    
    // Debug: print x and y values
    for (i = 0; i < n; i++) {
        printf("x[%d] = %.6f, y[%d] = %.6f\n", i, x[i], i, y[i]);
    }
    
    // Apply Simpson's rules
    if ((n - 1) % 2 == 0) {
        I = simpson_1by3(y, n, h); // Simpson's 1/3 Rule
    } else if ((n - 1) % 3 == 0) {
        I = simpson_3by8(y, 0, n, h); // Simpson's 3/8 Rule
    } else {
        int split = n - 4; // Last 3 intervals for 3/8 Rule
        I = simpson_1by3(y, split + 1, h); // Apply 1/3 Rule to first part
        I += simpson_3by8(y, split, n, h); // Apply 3/8 Rule to last part
    }
    
    // Print the result
    printf("Integrated value: %f\n", I);
    return 0;
}
