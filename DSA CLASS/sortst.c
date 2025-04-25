
#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *top1=NULL;
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
struct stack *sort(struct stack *);
void display(struct stack *);
int peek(struct stack *);

int main()
{
    int n,c;
    do
    {
        printf("\n---MENU---");
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                printf("\nEnter the number to be inserted onto the stack: ");
                scanf("%d", &n);
                top=push(top,n);
                break;

            case 2:
                top=pop(top);
                break;

            case 3:
                printf("\nStack:\n");
                display(top);
                break;

            case 4:
                printf("Exiting...");
                break;

            /*default:
                printf("\nINVALID CHOICE!!! TRY AGAIN!!!\n");*/
        }
    }while(c!=4);
    return 0;
}
struct stack *push(struct stack *top1, int val)
{
    struct stack *new=(struct stack *)malloc(sizeof(struct stack));
    if(!new)
    {
        printf("\nMEMORY ALLOCATION FAILED...");
        return top1;
    }
    new->data=val;
    new->next=top1;
    top1=new;
    return top1;
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
    printf("\n%d got deleted", ptr->data);
    free(ptr);
    return top;
}
int peek(struct stack *top)
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
struct stack *sort(struct stack *top)
{
    if (top==NULL || top->next==NULL)
        return top;
    int num;
    while(top!=NULL)
    {
        if(top->data > top->next->data)
        {
            num=top->data;
            top=pop(top);
            top1=push(top1,num);
        }
        else
        {
            
        }
        top->next->next = top;
        top->next = NULL;
    return rest;
}
