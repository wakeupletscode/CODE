//Read 2 polynomials using 1D array and perform their addition
#include <stdio.h>
void read(int poly[], int d) 
{
    printf("Enter the coefficients (from highest degree to lowest):\n");
    for (int i = 0; i <= d; i++) 
    {
        scanf("%d", &poly[i]);
    }
}
void add(int p1[], int p2[], int res[], int d)
{
    for (int i = 0; i <= d; i++) 
    {
        res[i] = p1[i] + p2[i];
    }
}
void display(int poly[], int d) 
{
    for (int i = 0; i <= d; i++) 
    {
        if (poly[i] != 0) {
            if (i != 0 && poly[i] > 0) 
            {
                printf(" + ");
            }
            if (d - i == 0) 
            {
                printf("%d", poly[i]);
            }
            else if (d - i == 1) 
            {
                printf("%dx", poly[i]);
            } 
            else 
            {
                printf("%dx^%d", poly[i], d - i);
            }
        }
    }
    printf("\n");
}
int main() 
{
    int d;
    printf("Enter the degree of the polynomials: ");
    scanf("%d", &d);
    int p1[d + 1], p2[d + 1], res[d + 1];
    printf("Polynomial 1:\n");
    read(p1, d);
    printf("Polynomial 2:\n");
    read(p2, d);
    add(p1, p2, res, d);
    printf("Resultant Polynomial after addition:\n");
    display(res, d);
    return 0;
}
