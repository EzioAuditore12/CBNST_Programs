#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter the number of terms you want:");
    scanf("%d",&n);
    float X[n],Y[n];
    printf("Enter the x intervals:\n");
    for(int i=0;i<n;i++){
        scanf("%f",&X[i]);
    }
     printf("Enter the y intervals:\n");
    for(int i=0;i<n;i++){
        scanf("%f",&Y[i]);
    }
    float x;
    printf("Enter the value of for which you want to interpolate y:");
    scanf("%f",&x);
    float sum=0;
  
    for(int i=0;i<n;i++){
        float term=1;
        for(int j=0;j<n;j++){
            if(i!=j){
                term=term*((x-X[j])/(X[i]-X[j]));
            }
        }
        sum+=term*Y[i];
    }
    printf("\nValue at X=%g is = %f", x,sum);
    return 0;
}

