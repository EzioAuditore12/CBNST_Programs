#include<stdio.h>
#include<math.h>
#define EPSILON 0.00001
float findValueat(float x){
    return x*cos(x)-x*x;
}
float differenciate(float x){
    return cos(x)-x*sin(x)-2*x;
}
int main()
{
    int maxIteration,i=1;
    float x1,x2;
    printf("Enter the max iteration you want:");
    scanf("%d",&maxIteration);
    do{
        printf("Enter x1 and x2:");
        scanf("%f%f",&x1,&x2);
        if(findValueat(x1)*findValueat(x2)>0){
            printf("Invalid roots\n");
            continue;
        }    
        else{
            printf("Roots are %f and %f\n",x1,x2);
            break;
        }
    }while(1);
float x0,x;
if(fabs(findValueat(x1))<fabs(findValueat(x2))){
    x0=x1;
}
else{
    x0=x2;
}
do{
x=x0-(findValueat(x0)/differenciate(x0));
printf("Iteration %d and Roots %f\n",i,x);
if(fabs(x0-x)<EPSILON){
    printf("Root %f Iteation %d",x,i);
    return 0;
}
x0=x;
i++;
}while(i<=maxIteration);
printf("Final root %f Iteration %d\n",x,--i);
return 0;
}