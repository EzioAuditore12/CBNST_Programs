#include<stdio.h>
#include<math.h>
#define EPSILON 0.0009
float f(float x){
    return cos(x)-3*x+1;
}
float g(float x){
    return (1+cos(x))/3;
}
float dg(float x){
    return (-sin(x))/3;
}
int main()
{
float x1,x2,x,x3;
int i=1;
printf("Enter the intervals x1 and x2:");
scanf("%f%f",&x1,&x2);
if(f(x1)*f(x2)<1){
    x=(x1+x2)/2;
    printf("Root %f Iteration %d\n",x,i);
    if(fabs(dg(x1))<1 && fabs(dg(x2))<1){
        do{
        x3=g(x);
        printf("X%d=%lf\n", i, x3);
        if(fabs(x3-x)<EPSILON){
            break;
        }
        x=x3;
        i++;
        }while(1);
        printf("Number of Iterations=%d\n", i);
        printf("Root: %lf\n", x3);
    }
    else
        {
            printf("The function does not converge in this interval.\n");
        }
}
else
    {
        printf("Invalid inputs! The function does not have a root in the given interval.\n");
    }

return 0;
}