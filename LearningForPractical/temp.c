#include<stdio.h>
float fact(int n)
{
    float f=1.0;
    for(int i=2;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}
float P(float p,int n)
{
    float temp = p;
    for(int i=1;i<n;i++)
    {
        temp=temp*(temp-i);
    }
    return temp;
}
int main()
{
    int n,i,j;
    printf("Enter number of data elements:");
    scanf("%d",&n);
    float x[n];
    float y[n][n];
    printf("Enter the coordinates given:\nx y\n");
    for(i=0;i<n;i++)
    {
        scanf("%f\t%f",&x[i],&y[i][0]);
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            y[j][i]=y[j+1][i-1]-y[j][i-1];
        }
    }
    printf("\nDifference table:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            printf("%f  ",y[i][j]);
        }
        printf("\n");
    }
    float v,x0,p,sum;
    printf("Enter x to find y:");
    scanf("%f",&v);
    i=0;
    while(v>=x[i])
    {
        i++;
    }
    x0=x[--i];
    printf("\nx0=%f\n",x0);

    sum=y[i][0];
    p=(v-x0)/(x[1]-x[0]);
    for(j=1;j<n;j++)
    {
        sum=sum+(P(p,j)*y[i][j])/fact(j);
    }
    printf("Interpolated value=%f",sum);
return 0;
}