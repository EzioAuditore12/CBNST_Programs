#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
float f(float x){
    return x*x*x-2*x-5;
}
float bisect(float x1,float x2){
    return (x1+x2)/2;
}
int main(){
    int n,i=1;
    printf("Enter the max number of iteration you want:");
    scanf("%d",&n);
    float x1,x2;
    printf("Enter the intervals:");
    scanf("%f%f",&x1,&x2);
    float x=bisect(x1,x2);
    float x0,x3;
    do{
        if(f(x1)*f(x2)<0){
            x2=x;
        }
        else{
            x1=x;
        }
        x3=bisect(x1,x2);
        printf("Iteration %d Root %f\n",i,x);
        if(fabs(x3-x)<EPSILON){
            printf("Iteration %d Root %f\n",i,x);
            return 0;
        }
        x=x3;
        i++;
    }while(i<=n);
    printf("FInal root %f Iteration %d\n",x,--i);
}