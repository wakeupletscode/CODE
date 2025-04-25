//program to mulitply 2 polynomials
#include<stdio.h>
#include<stdlib.h>
void read(int **a, int n) 
{
    printf("\nEnter the polynomial:");
    for(int i=0; i<n; i++) 
    {
        printf("\nEnter polynomial term no. %d:\n", i + 1);
        printf("Enter coefficient: ");
        scanf("%d", &a[0][i]);
        printf("Enter degree: ");
        scanf("%d", &a[1][i]);
    }
}
void multiply(int **a, int n, int **b, int m, int **c, int *size) 
{
    int k = 0;
    for(int i=0; i <(n+m-1); i++) 
    {
        c[0][i] = 0;
        c[1][i] = 0;
    }
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<m; j++) 
        {
            int coeff = a[0][i] * b[0][j];
            int degree = a[1][i] + b[1][j];
            int found= 0;
            for(int x =0; x< k; x++) 
            {
                if(c[1][x]==degree) 
                {
                    c[0][x] += coeff;
                    found = 1;
                    break;
                }
            }
            if(!found) 
            {
                c[0][k] = coeff;
                c[1][k]=degree;
                k++;
            }
        }
    }
    *size=k;
}
int main() 
{
    int n, m;
    printf("\nEnter no. of terms in the 1st polynomial: ");
    scanf("%d", &n);
    printf("\nEnter no. of terms in the 2nd polynomial: ");
    scanf("%d", &m);
    int **a = (int **)malloc(2 * sizeof(int *));
    int **b = (int **)malloc(2 * sizeof(int *));
    int **c = (int **)malloc(2 * sizeof(int *));
    for(int i = 0; i < 2; i++) 
    {
        a[i] = (int *)malloc(n * sizeof(int));
        b[i] = (int *)malloc(m * sizeof(int));
        c[i] = (int *)malloc((n + m - 1) * sizeof(int));
    }
    read(a, n);
    read(b, m);
    int size;
    multiply(a, n, b, m, c, &size);
    printf("\nResultant Polynomial: ");
    for(int i = 0; i < size; i++) 
    {
        if(i != 0 && c[0][i] > 0) 
        {
            printf("+ ");
        }
        printf("%dx^%d ", c[0][i], c[1][i]);
    }
    printf("\n");
    for(int i = 0; i < 2; i++) 
    {
        free(a[i]);
        free(b[i]);
        free(c[i]);
    }
    free(a);
    free(b);
    free(c);
    return 0;
}
