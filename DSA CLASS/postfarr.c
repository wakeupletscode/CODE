#include <stdio.h>

#define MAX 100

char stk[MAX];
int top = -1;

void push(int val) 
{
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stk[++top]=val;
}
int isoperator(char a)
{
    if(a=='*'||a=='/'||a=='%')
        return 2;
    else if(a=='+'||a=='-')
        return 1;
    else
        return 0;
}


char pop() 
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
    int n;
    char v;
    char c[98];
    printf("\nEnter the array size (max 98): ");
    scanf("%d", &n);

    if (n > 98) 
    {
        printf("Array size exceeds maximum stack size of %d.\n", MAX);
        return 1;
    }
    a[0]='(';
    a[n+1]=')';
    printf("\nEnter the postfix expression: ");
    for (i = 1; i < n+1; i++) 
    {
        scanf("%[^\n]s", c[i]);
    }
    n=n+2;
    int j=0;
    char b[n];
    for(int i=0;i<n;i++)
    {
        if(a[i]=='('||a[i]=='{'||a[i]=='[')
            push(top,a[i]);
        if(isalpha[a[i]])
        {    
            b[j]=a[i];
            j++;
        }
        if(isoperator(a[i])==2)
        {
            push(top,a[i]);
        }
        if(isoperator(a[i])==1 && isoperator(stk[i-1])!=2)
            push(top,a[i]);
        if(isoperator(a[i])==1 && isoperator(stk[i-1])==2)
        {
            v=pop(a[i]);
            b[j]=v;
            j++;
        }
        if(a[i]==')'||a[i]=='}'||a[i]==']')
        {
            v=pop(top);
            b[j]=v;
            j++;
        }
    }
}
