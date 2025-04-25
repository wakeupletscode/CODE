//Program to store and add 2 polynomials using 2-D array
#include<stdio.h>
#include<stdlib.h>
void read(int **a, int n,int **b, int m)
{
    printf("\nEnter 1st polynomial");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter polynomial term no. %d: \n", i);
        printf("Enter coefficient: ");
        scanf("%d", &a[0][i]);
        printf("Enter degree: ");
        scanf("%d", &a[1][i]);
    }
        printf("\nEnter 2nd polynomial");
    for(int i=0;i<m;i++)
    {
        printf("\nEnter polynomial term no. %d: \n", i);
        printf("Enter coefficient: ");
        scanf("%d", &b[0][i]);
        printf("Enter degree: ");
        scanf("%d", &b[1][i]);
    }
}
void add(int **a, int n, int **b, int m, int **c) 
{
    int i=0, j=0, k=0;
    while (i<n && j<m) 
    {
        if (a[1][i]>b[1][j]) 
        {
            c[0][k]=a[0][i];
            c[1][k]=a[1][i];
            i++;
        } 
        else if (a[1][i]<b[1][j]) 
        {
            c[0][k]=b[0][j];
            c[1][k]=b[1][j];
            j++;
        } 
        else 
        {
            c[0][k]=a[0][i]+b[0][j];
            c[1][k]=a[1][i];
            i++;
            j++;
        }
        k++;
    }
    while (i<n) 
    {
        c[0][k] = a[0][i];
        c[1][k] = a[1][i];
        i++;
        k++;
    }
    while (j < m) {
        c[0][k] = b[0][j];
        c[1][k] = b[1][j];
        j++;
        k++;
    }
}
int main()
{
    int m,n;
    printf("\nEnter no. of terms in the 1st polynomial: ");
    scanf("%d", &n);
    printf("\nEnter no. of terms in the 2nd polynomial: ");
    scanf("%d", &m);
    int **a=(int **)malloc(2 * sizeof(int *));
    for (int i=0; i<2; i++) 
    {
        a[i]=(int *)malloc(n * sizeof(int));
    }
    int **b=(int **)malloc(2 * sizeof(int *));
    for (int i=0; i<2; i++) 
    {
        b[i]=(int *)malloc(m * sizeof(int));
    }
    int **c=(int **)malloc(2 * sizeof(int *));
    for (int i=0; i<2; i++) 
    {
        c[i]=(int *)malloc((m+n) * sizeof(int));
    }
    read(a,n,b,m);
    add(a,n,b,m,c);
    printf("\nResultant Polynomial:\n");
    for (int i=0; i<(m+n); i++) 
    {
        if (c[0][i]!= 0) 
        { 
            printf("%dx^%d ", c[0][i],c[1][i]);
            if (i<(m+n-1) && c[0][i+1]>0) 
            {
                printf("+ ");
            }
        }
    }
    for (int i=0; i<2; i++) 
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
