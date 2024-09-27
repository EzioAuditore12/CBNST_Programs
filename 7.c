////Gauss ELimination
#include<stdio.h>
#include<math.h>
int main(){
    int m=3;
    int n=4;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("Enter value of %d %d",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
               printf("%d ",arr[i][j]);
        }
     printf("\n");
    }
}
