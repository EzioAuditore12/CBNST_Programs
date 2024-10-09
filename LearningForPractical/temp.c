#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of terms you want: ");
    scanf("%d", &n);

    // Use fixed-size array or consider using dynamic memory allocation
    float arr[n][n + 1];

    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i][0]);  // Store x values in the first column
    }

    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i][1]);  // Store y values in the second column
    }

    // Constructing the difference table
    for (int j = 2; j <= n; j++) {
        for (int i = 0; i <= n - j; i++) {
            arr[i][j] = arr[i + 1][j - 1] - arr[i][j - 1];
        }
    }

    // Print the difference table
    printf("Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <=n-i; j++) {
            printf("%f\t", arr[i][j]); // Print each element with tab spacing
        }
        printf("\n");
    }

    float x;
    printf("Enter the value of x for which you want y: ");
    scanf("%f", &x);
    
    float h = arr[1][0] - arr[0][0];  // Calculate h
    float u = (x - arr[0][0]) / h;  // Calculate u
    float y = arr[0][1];  // Start with the first y value
    float u1 = u;
    int fact = 1;

    // Calculate the interpolated value of y
    for (int i = 2; i <= n; i++) {
        fact *= (i - 1);  // Factorial calculation
        y += (u1 * arr[0][i]) / fact;  // Adding terms to y
        u1 *= (u - (i - 1));  // Update u1 for next term
    }

    printf("\nValue at X = %f is = %f\n", x, y);
    return 0;
}
