#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter the number of terms you want: ");
    scanf("%d", &n);

    float x[n], y[n], xy[n], x2[n];
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter x[%d]: ", i + 1);
        scanf("%f", &x[i]);  
        printf("Enter y[%d]: ", i + 1);
        scanf("%f", &y[i]);  
        xy[i] = x[i] * y[i];
        x2[i] = x[i] * x[i];
        sumX += x[i];
        sumY += y[i];
        sumXY += xy[i];
        sumX2 += x2[i];
    }

    float a=((sumX2*sumY)-(sumXY*sumX))/((n*sumX2)-(sumX*sumX));
    float b=((n*sumXY)-(sumX*sumY))/((n*sumX2)-(sumX*sumX));

    printf("Equation of a+bx is y= %.2f+ %.2fx\n",a,b);
    return 0;
}
