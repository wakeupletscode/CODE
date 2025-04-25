#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *top=NULL;
struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
struct stack *reverse(struct stack *);
void display(struct stack *);
int peek(struct stack *);
int main()
{
    int n,c;
    do
    {
        printf("\n---MENU---");
        printf("\n1.push\n2.pop\n3.display\n4.reverse\n5.exit\n");
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
                top=reverse(top);
                printf("\nReversed Stack:\n");
                display(top);
                break;

            case 5:
                printf("Exiting...");
                break;

            /*default:
                printf("\nINVALID CHOICE!!! TRY AGAIN!!!\n");*/
        }
    }while(c!=5);
    return 0;
}
struct stack *push(struct stack *top, int val)
{
    struct stack *new=(struct stack *)malloc(sizeof(struct stack));
    if(!new)
    {
        printf("\nMEMORY ALLOCATION FAILED...");
        return top;
    }
    new->data=val;
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
struct stack* reverse(struct stack *top)
{
    if (top==NULL || top->next==NULL)
        return top;
    struct stack *rest = reverse(top->next);
    top->next->next = top;
    top->next = NULL;
    return rest;
}

