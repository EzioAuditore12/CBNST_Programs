#include<stdio.h>
#include<math.h>
int main()
{
    int n;
printf("Enter the number of terms you want:");
scanf("%d",&n);
float arr[n][n+1];
printf("Enter the value of x intervals:\n");
for(int i=0;i<n;i++){
    scanf("%f",&arr[i][0]);
}
printf("Enter the value of y intervals:\n");
for(int i=0;i<n;i++){
    scanf("%f",&arr[i][1]);
}
for(int j=2;j<n-n;j++){
    for(int i=0;i<=n-j;i++){
        arr[i][j]=arr[i+1][j-1]-arr[i][j-1];
    }
}
for(int i=0;i<n;i++){
    for(int j=0;j<=n-i;j++){
        printf("%f\t",arr[i][j]);
    }
    printf("\n");
}
float x;
printf("Enter the value of x at which you want to interpolate:");
scanf("%f",&x);
float h=arr[0][1]-arr[0][0];
float u=((x-arr[0][0])/h);
int f=1;
float u1=u;
float y=arr[0][1];
for(int i=2;i<=n;i++){
    f*=(u-1);
    y+=(u1*arr[0][i])/f;
    u1*=(u-(i-1));
}
printf("\nValue at X = %f is = %f\n", x, y);
return 0;
}