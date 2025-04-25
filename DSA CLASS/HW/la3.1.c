//Program to implement a sparse matrix
#include<stdio.h>
#include<stdlib.h>
void read(int **a, int m, int n)
{
    printf("\nEnter array elements: ");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}
void sparse(int **a, int m, int n)
{
    int c=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0)
                c++;
        }
    }
    int **b = (int **)malloc((c + 1) * sizeof(int *));
    for (int i=0; i<(c+1); i++) 
    {
        b[i] = (int *)malloc(3 * sizeof(int));
    }
    b[0][0]=m;
    b[0][1]=n;
    b[0][2]=c;
    int k=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    k=1;
    printf("\nSparse matrix: ");
    printf("\nRow\tColoumn\tValue");
    while(k<=c)
    {
        printf("\n%d\t%d\t%d", b[k][0], b[k][1], b[k][2]);
        k++;
    }
    for (int i=0; i<(c+1); i++) 
    {
        free(b[i]);
    }
    free(b);

}
int main()
{
    int m,n;
    printf("\nEnter array size: ");
    printf("\nNumber of rows: ");
    scanf("%d", &m);
    printf("Number of coloumns: ");
    scanf("%d", &n);
    int **a=(int **)malloc(m * sizeof(int *));
    for (int i=0; i<m; i++) 
    {
        a[i]=(int *)malloc(n * sizeof(int));
    }
    read(a,m,n);
    sparse(a,m,n);
    for (int i=0; i<m; i++) 
    {
        free(a[i]);
    }
    free(a);
    return 0;
}