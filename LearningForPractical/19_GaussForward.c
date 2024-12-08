#include<stdio.h>
#include<math.h>

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n;
    printf("Enter the number of terms you want: ");
    scanf("%d", &n);
    
    float arr[n][n+1];
    printf("Enter the value of x intervals:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i][0]);
    }
    
    printf("Enter the value of y intervals:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i][1]);
    }
    
    // Calculate the forward difference table
    for (int j = 2; j <= n; j++) {
        for (int i = 0; i <= n - j; i++) {
            arr[i][j] = arr[i+1][j-1] - arr[i][j-1];
        }
    }
    
    // Display the difference table
    printf("\nDifference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n - i; j++) {
            printf("%f\t", arr[i][j]);
        }
        printf("\n");
    }
    
    // Input the value of x for interpolation
    float x;
    printf("\nEnter the value of x at which you want to interpolate: ");
    scanf("%f", &x);
    
    // Calculate h and u
    float h = arr[1][0] - arr[0][0];
    float u = (x - arr[n/2][0]) / h;  // Centered around the middle value
    float y = arr[n/2][1];           // Starting with y at the middle point
    
    // Gauss Forward Interpolation formula
    float u_term = u;
    int mid = n / 2;
    for (int i = 2; i <= n; i++) {
        int k = (i - 1) / 2;
        if (i % 2 == 0) {
            y += (u_term * arr[mid - k][i]) / factorial(i - 1);
        } else {
            y += (u_term * arr[mid - k - 1][i]) / factorial(i - 1);
        }
        u_term *= (u - (i - 1));
    }
    
    printf("\nValue at X = %f is = %f\n", x, y);
    return 0;
}
