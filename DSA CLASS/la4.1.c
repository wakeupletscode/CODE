//create a linked list having n no. of nodes and traverse it
#include<stdio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);

struct node *create(struct node *start)
{
    struct node *new, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    while(num!=-1)
    {
        new=(struct node*)malloc(sizeof(struct node*));
        new->data=num;
        if(start==NULL)
        {
            new->next=NULL;
            start=new;
        }
        else
        {
            ptr->
        }
    }
}
