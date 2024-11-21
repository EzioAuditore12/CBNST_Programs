#include <stdio.h>

float function(float x, float y) {
    return x + y;
}

int main() {
    float x0, y0, xn, h;  
    printf("Enter initial values x0, y0, target xn, and step size h:\n");
    scanf("%f %f %f %f", &x0, &y0, &xn, &h);

    int n = (int)((xn - x0) / h)+1;  
    printf("Number of steps = %d\n", n);

    float x = x0;  
    float y = y0;  


    for (int i = 0; i < n; i++) {
        y = y + h * function(x, y);  
        x = x + h;                  
        printf("Step %d: x = %.4f, y = %.4f\n", i + 1, x, y);
    }

    printf("The value of y at x = %.4f is %.4f\n", xn, y);
    return 0;
}
