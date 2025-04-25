#include<stdio.h>
#include<stdlib.h>

int prime(int a)
{
    if(a<=1)
        return 0;
    for(int i=2;i<a;i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}
int main()
{
    int *a, n, s=0;
    printf("Enter the number of elements to be entered\n");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", (a+i));
    }
    for(int i = 0; i < n; i++)
    {
        if(prime(a[i])==1)
        s+=a[i];
    }
    printf("Sum of all prime elements in the array = %d\n", s);
    free(a);
}