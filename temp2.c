#include <stdio.h>
#include <math.h>
#define EPSILON 0.001

float f(float x, float C) {
    return pow(2*x*x + 4, 1.0/3.0) - C;
}

float differentiate(float x) {
    return (2*x) / (3 * pow(2*x*x + 4, 2.0/3.0));
}

int main() {
    int maxIteration, i;
    float a, b, x, x0, C;
    
    printf("Enter Maximum number of Iterations: ");
    scanf("%d", &maxIteration);
    
    printf("Enter the value of C (for the equation (2x^2 + 4)^(1/3) = C): ");
    scanf("%f", &C);
   
    do {
        printf("Enter the starting boundary values a and b: ");
        scanf("%f%f", &a, &b);
        
        if (f(a, C) * f(b, C) > 0) {
            printf("Boundary Values are Invalid. f(a) and f(b) have the same sign. Try again.\n");
            continue;
        } else {
            printf("Roots Lie between %f and %f\n", a, b);
            break;
        }
    } while (1);

    for (i = 1; i <= maxIteration; i++) {
        x0 = (a + b) / 2.0; 
        if (fabs(f(x0, C)) < EPSILON) {
            printf("Iterations = %d, Final Root = %f\n", i, x0);
            return 0;
        }
        
        if (f(a, C) * f(x0, C) < 0) {
            b = x0;
        } else {
            a = x0;
        }

        printf("Iterations = %d, Approximate Root = %f\n", i, x0);
    }
    
    printf("Root = %f after %d iterations\n", x0, --i);
    return 0;
}
