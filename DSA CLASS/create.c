#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *start=NULL;
struct Node *create(struct Node *);
struct Node *insert_beg(struct Node *, int );
int main()
{
    char ch;
    int val;
    do
    {
        printf("\n---MENU---");
        printf("\n1. Create a linked list");
        printf("\n2.Insert at the beggining")
        printf("\nPress any other key to exit\n");
        scanf(" %c", &ch);
        switch(ch)
        {
            case '1':
            start=create(start);
            printf("\nLinked list has been created");
            break;

            case 2:
            printf("\nEnter the node to be inserted at beggining: ");
            scanf("%d", &val);
            start=insert_beg(start)

        }
    } while (ch=='1');
    return 0;
}
struct Node *create(struct Node *start)
{
    struct Node *new_node,*ptr;
    int num,i=1;
    printf("\nEnter -1 to end");
    printf("\nEnter the data");
    printf("\nEnter node 1: ");
    scanf("%d", &num);
    new_node->next=NULL;
    while(num!=-1)
    {
        new_node=(struct Node *)malloc(sizeof(struct Node));
        new_node->data=num;
        if(new_node==NULL)
        {
            printf("\nMemory allocation failed...");
            return start;
        }
        new_node->next=NULL;
        if(start==NULL)
            start=new_node;
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=new_node;
        }
        i++;
        printf("Enter node %d: ", i);
        scanf("%d", &num);
    }
    return start;
}
struct Node *insert_beg(struct Node *start, int val) 
{
    struct Node *new_node =(struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) 
    {
        printf("\nMemory allocation failed...");
        return start;
    }
    new_node->data = val;
    new_node->next = start;
    start = new_node;
    return start;
}
