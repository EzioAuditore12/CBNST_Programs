#include<stdio.h>
#include<math.h>
#define EPSILON 0.0001
float findValueat(float x){
    return x*x*x-2*x-5;
}
float findAtX(float x1,float x2){
     return (x1*findValueat(x2) - x2 * findValueat(x1)) / (findValueat(x2) - findValueat(x1));
}
int main()
{
int maxIteration,i=1;
float x1,x2;
printf("Enter the max number of iteration you want:");
scanf("%d",&maxIteration);
do{
    printf("Enter the value of x1 and x2:");
    scanf("%f%f",&x1,&x2);
    if(findValueat(x1)*findValueat(x2)>0){
        printf("Roots are invalid\n");
        continue;
    }
    else{
        printf("Roots are %f and %f\n",x1,x2);
        break;
    }
}while(1);
float x=findAtX(x1,x2);
do{
if(findValueat(x1)*findValueat(x2)<0){
    x2=x;
}
else{
    x1=x;
}
float x3=findAtX(x1,x2);
printf("Iterations=%d  Roots=%f\n",i,x);  
if(fabs(x3-x)<EPSILON){
    printf("Root %f Iteration %d\n",x,i);
    return 0;
}
x=x3;
i++;
}while(i<=maxIteration);
printf("Final root = %f Total itertation %d\n",x,--i);
return 0;
}