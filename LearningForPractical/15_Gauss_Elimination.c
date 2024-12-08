#include<stdio.h>
int main()
{
int n;
printf("Enter the number of unknowns you want:");
scanf("%d",&n);
float arr[n][n+1];

printf("Enter the unknown matrix:\n");
for(int i=0;i<n;i++){
    for(int j=0;j<n+1;j++){
        scanf("%f",&arr[i][j]);
    }
}

for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        float ratio=arr[j][i]/arr[i][i];
        for(int k=0;k<n+1;k++){
            arr[j][k]=arr[j][k]-(ratio*arr[i][k]);
        }
    }
}

float values[n];

values[n-1]=arr[n-1][n]/arr[n-1][n-1];

for(int i=n-2;i>=0;i--){
    float sum=0;
    for(int j=i+1;j<n;j++){
        sum=sum+(arr[i][j]*values[j]);
    }
    values[i]=(arr[i][n]-sum)/arr[i][i];
}

printf("Values of unknowkns are:\n");
for(int i=0;i<n;i++){
    printf("%3f",values[i]);
}
return 0;
}