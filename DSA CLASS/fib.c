#include <stdio.h>
int fib(int n)
{
    int seq[1005];
    seq[0]=0;
    seq[1]=1;
    for(int i=2;i<=n;i++)
    {
        seq[i]=seq[i-1]+seq[i-2];
    }
    return seq[n];
}
int main()
{
    int n;
    do
    {
        printf("\nEnter: ");
        scanf("%d", &n);
        printf(": %d", fib(n));
    } while (n!=-1);
    return 0;
}