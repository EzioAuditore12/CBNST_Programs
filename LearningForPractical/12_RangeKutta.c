#include <stdio.h>

float function(float x, float y) {
    return x + y;
}

int main() {
    float x, y, h;
    int n;

    printf("Enter initial values of x and y (x0, y0): ");
    scanf("%f %f", &x, &y);

    printf("Enter step size (h): ");
    scanf("%f", &h);

    printf("Enter the number of steps: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        float k1 = h * function(x, y);
        float k2 = h * function(x + h / 2, y + k1 / 2);
        float k3 = h * function(x + h / 2, y + k2 / 2);
        float k4 = h * function(x + h, y + k3);

        y += (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        x += h;

        printf("After step %d: x = %.4f, y = %.4f\n", i + 1, x, y);
    }

    return 0;
}
