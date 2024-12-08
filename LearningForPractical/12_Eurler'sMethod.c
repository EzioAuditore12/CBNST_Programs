#include<stdio.h>

float function(float x, float y) {
    return (y-x)/(y+x);
}

int main() {
    float x0, y0, x, h;
    scanf("%f%f%f%f", &x0, &y0, &x, &h);  
    int n = (int)((x - x0) / h); 
    printf("No. of steps = %d\n", n);

    float y = y0;  

    while(x <= x0) { 
        y = y + h * function(x, y);  
        x = x + h;  
    }

    printf("Value of y is %.4f\n", y);  
    return 0;
}
