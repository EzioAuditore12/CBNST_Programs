#include<stdio.h>
#include<math.h>
float f(float x)
{
     return x*x*x-2*x-5;
}
float root(float a,float b)
{
    int i=1;
    float x;
    if(f(a)*f(b)<0)
    {
        while(1)
        {
            x=b-((b-a)*f(b))/(f(b)-f(a));
            printf("X%d=%f\n",i,x);
            if(f(a)*f(x)<0)
            {
                b=x;
            }
            else
            {
                a=x;
            }
            if(fabs(f(x))<0.0009)
            {
                break;
            }
            i++;
        }
        return x;
    }
    else
    {
        printf("Invalid Inputs!!");
    }
}
int main()
{
    float a,b,r;
    printf("Enter intervals:");
    scanf("%f%f",&a,&b);
    r=root(a,b);
    printf("Root = %f",r);
return 0;
}