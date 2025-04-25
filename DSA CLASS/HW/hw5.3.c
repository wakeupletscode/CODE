//Addition of 2 polynomials using 2-D array
#include <stdio.h>
void r(int p[2][100], int n) 
{
    printf("Enter coefficients and degrees:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Coeff %d: ", i + 1);
        scanf("%d", &p[0][i]);
        printf("Degree %d: ", i + 1);
        scanf("%d", &p[1][i]);
    }
}
void a(int p1[2][100], int p2[2][100], int res[2][100], int n1, int n2) 
{
    int k = 0;
    for (int i = 0; i < n1; i++) 
    {
        int found = 0;
        for (int j = 0; j < n2; j++) 
        {
            if (p1[1][i] == p2[1][j]) 
            {
                res[0][k] = p1[0][i] + p2[0][j];
                res[1][k] = p1[1][i];
                k++;
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            res[0][k] = p1[0][i];
            res[1][k] = p1[1][i];
            k++;
        }
    }
    for (int j = 0; j < n2; j++) 
    {
        int found = 0;
        for (int i = 0; i < n1; i++) 
        {
            if (p2[1][j] == p1[1][i]) 
            {
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            res[0][k] = p2[0][j];
            res[1][k] = p2[1][j];
            k++;
        }
    }
}
void d(int p[2][100], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        if (p[0][i] != 0) {
            if (i != 0 && p[0][i] > 0) 
            {
                printf(" + ");
            }
            if (p[1][i] == 0) 
            {
                printf("%d", p[0][i]);
            } 
            else if (p[1][i] == 1) 
            {
                printf("%dx", p[0][i]);
            } 
            else 
            {
                printf("%dx^%d", p[0][i], p[1][i]);
            }
        }
    }
    printf("\n");
}
int main() 
{
    int n1, n2;
    printf("Enter number of terms in first poly: ");
    scanf("%d", &n1);
    int p1[2][100];
    printf("Poly 1:\n");
    r(p1, n1);
    printf("Enter number of terms in second poly: ");
    scanf("%d", &n2);
    int p2[2][100];
    printf("Poly 2:\n");
    r(p2, n2);
    int res[2][100];
    a(p1, p2, res, n1, n2);
    printf("Resultant Polynomial after addition:\n");
    d(res, n1 + n2);
    return 0;
}
