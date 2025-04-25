#include<stdio.h>
int main()
{
    int arr[10];
    int i=0;
    for(int j=0;j<10;j++)
    {
        arr[j]=j+1;
    }
    printf("%d", arr[++i]);
}