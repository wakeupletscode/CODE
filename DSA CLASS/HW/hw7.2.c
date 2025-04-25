//program to divide 2 polynomials
#include <stdio.h>
#include <stdlib.h>
void read(int **p, int t) 
{
    printf("\nEnter the polynomial:");
    for (int i = 0; i < t; i++) 
    {
        printf("\nEnter polynomial term no. %d:\n", i+1);
        printf("Enter coefficient: ");
        scanf("%d", &p[0][i]);
        printf("Enter degree: ");
        scanf("%d", &p[1][i]);
    }
}
void divide(int **div, int div_t, int **divs, int divs_t, int **q, int **r, int *q_t, int *r_t) 
{
    int temp[2][div_t];
    for (int i=0; i<div_t; i++) 
    {
        r[0][i] = div[0][i];
        r[1][i] = div[1][i];
    }
    *r_t = div_t;
    int q_i = 0;
    while (*r_t > 0 && r[1][0] >= divs[1][0]) 
    {
        int coeff = r[0][0] / divs[0][0];
        int deg = r[1][0] - divs[1][0];
        q[0][q_i] = coeff;
        q[1][q_i] = deg;
        q_i++;
        for (int i = 0; i < divs_t; i++)
        {
            temp[0][i] = coeff * divs[0][i];
            temp[1][i] = deg + divs[1][i];
        }
        int new_r_t = 0;
        for (int i = 0; i < *r_t; i++) 
        {
            int found = 0;
            for (int j = 0; j < divs_t; j++) 
            {
                if (r[1][i] == temp[1][j]) 
                {
                    r[0][i] -= temp[0][j];
                    found = 1;
                    break;
                }
            }
            if (r[0][i] != 0) {
                r[0][new_r_t] = r[0][i];
                r[1][new_r_t] = r[1][i];
                new_r_t++;
            }
        }
        *r_t = new_r_t;
    }
    *q_t = q_i;
}
int main() 
{
    int div_t, divs_t;
    printf("\nEnter no. of terms in the dividend polynomial: ");
    scanf("%d", &div_t);
    printf("\nEnter no. of terms in the divisor polynomial: ");
    scanf("%d", &divs_t);
    int **div = (int **)malloc(2 * sizeof(int *));
    int **divs = (int **)malloc(2 * sizeof(int *));
    int **q = (int **)malloc(2 * sizeof(int *));
    int **r = (int **)malloc(2 * sizeof(int *));
    for (int i=0; i<2; i++) 
    {
        div[i] = (int *)malloc(div_t * sizeof(int));
        divs[i] = (int *)malloc(divs_t * sizeof(int));
        q[i] = (int *)malloc(div_t * sizeof(int));
        r[i] = (int *)malloc(div_t * sizeof(int));
    }
    read(div, div_t);
    read(divs, divs_t);
    int q_t, r_t;
    divide(div, div_t, divs, divs_t, q, r, &q_t, &r_t);
    printf("\nQuotient: ");
    for (int i = 0; i < q_t; i++) 
    {
        if (i != 0 && q[0][i] > 0) 
        {
            printf("+ ");
        }
        printf("%dx^%d ", q[0][i], q[1][i]);
    }
    printf("\nRemainder: ");
    for (int i = 0; i < r_t; i++) 
    {
        if (i != 0 && r[0][i] > 0) 
        {
            printf("+ ");
        }
        printf("%dx^%d ", r[0][i], r[1][i]);
    }
    printf("\n");
    for (int i = 0; i < 2; i++) 
    {
        free(div[i]);
        free(divs[i]);
        free(q[i]);
        free(r[i]);
    }
    free(div);
    free(divs);
    free(q);
    free(r);
    return 0;
}
