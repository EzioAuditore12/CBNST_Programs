#include <stdio.h>
#include <math.h>
double f(double x)
{
    return (cos(x)-3*x+1);
}
double g(double x)
{
    return ((1.0+cos(x))/3.0);
}
double dg(double x)
{
    return(-sin(x)/3.0);
}
double root(double a,double b)
{
    int i = 1;
    double x0,x1;
    if(f(a)*f(b)<0)
    {
        x0=(a+b)/2.0;
        printf("X0=%lf\n",x0);
        if((fabs(dg(a))<1) && (fabs(dg(b)<1)))
        {
            while(1)
            {
                x1=g(x0);
                printf("X%d=%lf\n",i,x1);
                if((fabs(x1-x0))<0.0009)
                {
                    break;
                }
                x0=x1;
                i++;
            }
            printf("Number of Iterations=%d\n",i);
            return x1;
        }
    }
    else
    {
        printf("Invalid inputs!!");
    }
}
int main()
{
    double a, b;
    printf("Enter the intervals: ");
    scanf("%lf %lf", &a, &b);
    double r=root(a,b);
    printf("Root: %lf\n", r);
return 0;
}