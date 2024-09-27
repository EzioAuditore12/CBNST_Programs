//Newton Backward Method
#include<stdio.h>
#include<math.h>

float factorial(int n){
    float f = 1.0;
    for(int i=2; i<=n; i++){
        f = f * i;
    }
    return f;
}

float P(float p, int n){
    float temp = p;
    for(int i=1; i<n; i++){
        temp = temp * (p + i);  
    }
    return temp;
}

int main(){
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    float x[n], y[n][n];

    printf("Enter the values of x:\n");
    for(int i=0; i<n; i++){
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter the values of y:\n");
    for(int i=0; i<n; i++){
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    
    for(int i=1; i<n; i++){
        for(int j=n-1; j>=i; j--){
            y[j][i] = y[j][i-1] - y[j-1][i-1];
        }
    }

   
    printf("Backward Difference Table:\n");
    for(int i=0; i<n; i++){
        printf("x[%d] = %f ", i, x[i]);
        for(int j=0; j<=i; j++){
            printf("%f ", y[i][j]);
        }
        printf("\n");
    }

    float value;
    printf("Enter the value of x to interpolate: ");
    scanf("%f", &value);

    float p = (value - x[n-1]) / (x[1] - x[0]);

    
    float Y = y[n-1][0];  
    for(int i=1; i<n; i++){
        Y = Y + (P(p, i) * y[n-1][i]) / factorial(i);
    }

    printf("The interpolated value at x = %f is %f\n", value, Y);
    
    return 0;
}
