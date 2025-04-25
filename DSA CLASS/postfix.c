//POSTFIX
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct stack
{
    char data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *, char);
struct stack *pop(struct stack *);
void display(struct stack *);
char peek(struct stack *);

int main()
{
    char *a=malloc(100*sizeof(char));
    printf("\nEnter the infix expression: ");
    scanf("%[^\n]s", a);
    int l=strlen(a);
    a=realloc(a,l+2);

    int t=0;
    for(int i=l;i>0;i--)
    {
        a[i]=a[i-1];
    }
    a[0]='(';
    a[l+1]=')';
    l+=2;
    char *b=malloc(l*sizeof(char));
    for(int i=0;i<l;i++)
    {
        if(a[i]=='('||a[i]=='{'||a[i]=='[')
        {
            top=push(top,a[i]);
            if(isalpha[a[i]])
                b[i]=a[i];
            if(a[i]==')'||a[i]=='}'||a[i]==']')
            {
            top=pop(top);
             
            }
    }
}
struct stack *push(struct stack *top, char v)
{
    struct stack *new=(struct stack *)malloc(sizeof(struct stack));
    if(!new)
    {
        printf("\nMEMORY ALLOCATION FAILED...");
        return top;
    }
    new->data=v;
    new->next=top;
    top=new;
    return top;
}
struct stack *pop(struct stack *top)
{
    if(top==NULL)
    {
        printf("\nSTACK UNDERFLOW...");
        return top;
    }
    struct stack *ptr=top;
    top=top->next;
    free(ptr);
    return top;
}
char peek(struct stack *top)
{
    if(top==NULL)
        return -1;
    return top->data;
}
void display(struct stack *top)
{
    struct stack *ptr=top;
    if(top==NULL)
    {
        printf("\nSTACK IS EMPTY...");
        return;
    }
    while(ptr!=NULL)
    {
        printf("\n%d ", ptr->data);
        ptr=ptr->next;
    }
}
