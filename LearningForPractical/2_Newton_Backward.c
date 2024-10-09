#include<stdio.h>
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
for(int j=2;j<=n;j++){
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
printf("Enter the value of x at which you want to interpolate y:");
scanf("%f",&x);
float h=arr[1][0]-arr[0][0];
float u=(x-arr[n-1][0])/h;
int f=1;
float u1=u;
float y=arr[n-1][1];
int j=2;
for(int i=n-2;i>=0;i--){
    y+=(u1*arr[i][j])/f;
    f=f*j;
    u1=u1*(u+(j-1));
    j++;
}
printf("\n\nValue at X=%f is = %f", x,y);
return 0;
}