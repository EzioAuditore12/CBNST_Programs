#include<stdio.h>
#include<math.h>
float equation(float x){
    return x*x*x;
}
int main()
{
float u,l,h;
printf("Enter the upper limit of equation:");
scanf("%f",&u);
printf("Enter the lower limit of equation:");
scanf("%f",&l);
printf("Enter the interval sizes:");
scanf("%f",&h);
int n =(int)ceil((u-l)/h);
n=n+1;
printf("Value of n is %d\n",n);
float x[n],y[n];
for(int i=0;i<n;i++){
    x[i]=l+(i*h);
    y[i]=equation(x[i]);
}
for (int i = 0; i < n; i++) {
    x[i] = l + i * h;
    y[i] = equation(x[i]);
    printf("x[%d] = %.6f, y[%d] = %.6f\n", i, x[i], i, y[i]); // Debug print
}

float sumEven=0,sumOdd=0;
for(int i=1;i<n-1;i++){
    if(i%2==0){
        sumEven+=y[i];
    }
    else{
        sumOdd+=y[i];
    }
}
float sum=(4*(sumOdd))+(2*(sumEven));
sum+=y[0]+y[n-1];
sum=(h/3)*sum;
printf("Answer is %f",sum);
return 0;
}