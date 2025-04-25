#include <stdio.h>
#define MAX 10
int stk[MAX];
int top = -1;
void push(int val) 
{
    if (top == MAX - 1) 
        printf("Stack Overflow\n");
    else 
        stk[++top] = val;
}
int pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else 
        return stk[top--];
}

int main() 
{
    int val, n, i;
    int a[10];
    printf("\nEnter the array size (max 10): ");
    scanf("%d", &n);
    if (n > MAX) 
    {
        printf("Array size exceeds maximum stack size of %d.\n", MAX);
        return 1;
    }
    printf("\nEnter the elements of the array:\n");
    for (i = 0; i < n; i++) 
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        push(a[i]);
    for (i = 0; i < n; i++) 
    {
        val = pop();
        a[i] = val;
    }
    printf("\nThe reversed array is:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", a[i]);
    }
    return 0;
}
