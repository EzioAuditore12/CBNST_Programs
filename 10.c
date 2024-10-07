#include <stdio.h>
#include <math.h>
#define X 2

void gauss_seidel(float x[X][X + 1], float ae, int mxit) {
    float a[X], t, e, max;
    int i, j, r;

    for (i = 0; i < X; i++) {
        a[i] = 0;
    }

    printf("Iteration\tx[1]\tx[2]\n");
   
    for (r = 1; r <= mxit; r++) {
        max = 0;
        
        for (i = 0; i < X; i++) {
            float s = 0;

            for (j = 0; j < X; j++) {
                if (j != i) {
                    s += x[i][j] * a[j];
                }
            }

            t = (x[i][X] - s) / x[i][i];
            e = fabs(a[i] - t);
            a[i] = t;

            if (e > max) {
                max = e;
            }
        }

        printf(" %5d\t", r);
        for (i = 0; i < X; i++) {
            printf(" %9.4f\t", a[i]);
        }
        printf("\n");

        if (max < ae) {
            printf("Converges in %3d iterations\n", r);
            for (i = 0; i < X; i++) {
                printf("a[%3d]=%7.4f\n", i + 1, a[i]);
            }
            return;
        }
    }
    printf("Did not converge within the maximum iterations.\n");
}

int main() {
    float x[X][X + 1], ae;
    int mxit;

    printf("Enter the elements of the augmented matrix row-wise:\n");
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < X + 1; j++) {
            scanf("%f", &x[i][j]);
        }
    }
 
    printf("Enter the allowed error and maximum number of iterations: ");
    scanf("%f %d", &ae, &mxit);

    gauss_seidel(x, ae, mxit);
    
    return 0;
}
