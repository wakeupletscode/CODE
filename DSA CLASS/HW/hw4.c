/*Q4.Implement a function to rotate an array of integers by 'k' positions 
to the right. For example, if the array is [1, 2, 3, 4, 5, 6, 7] and k is 3, 
the array should be modified to [5, 6, 7, 1, 2, 3, 4].*/
#include <stdio.h>
#include <string.h>
int main()
{
    int n,k,j=0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n],b[n];
    printf("Enter %d integers:\n", n);
    for (int i=0; i<n; i++) 
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the value of k: ");
    scanf("%d", &k);
    if(k>=n)
        k=n%k;
    for (int i = (n-k); i<n; i++) 
    {
        b[j]=a[i];
        j++;
    }
    for (int i=0; i<(n-k); i++) 
    {
        b[j]=a[i];
        j++;
    }
    for (int i=0; i<n; i++) 
    {
        a[i]=b[i];
    }
    printf("\nThe shifted array is: ");
    for (int i=0; i<n; i++) 
    {
        printf("%d, ", a[i]);
    }
}