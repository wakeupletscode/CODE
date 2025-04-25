#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *root=NULL;
struct tree *create(struct tree *);

struct tree *add(struct tree *, int );
struct tree *delete(struct tree *, int );
int main()
{
    int ch, num, num2;
    printf("\n---MENU---\n");
    printf("1.Create tree\n2.Traverse\n3.Add node\n4.Delete\n5.Exit\nEnter choice: ");
    scanf("%d", &ch);
    do
    {
        switch(ch)
        {
            case 1:
            root=create(root);
            printf("\nTree has been created...");
            break;
            
            case 2:
            printf("\nTree: ");
            root=traverse(root);
            break;

            case 3:
            printf("\nEnter the number you wanna add: ");
            scanf("%d", &num);
            root=add(root,num);
            printf("\n%d has been added to the tree...", num);
            break;

            case 4:
            printf("\nEnter the number you wanna delete: ");
            scanf("%d", &num2);
            root=add(root,num2);
            printf("\n%d has been deleted...", num2);
            break;

            default:
            printf("\nINVALID CHOICE\tENTER A NUMBER FROM 1-5\n");
            break;

            case 5:
            printf("\nExitting...");
        }
    } while (ch!=5);
    return 0;
}
struct tree *add(struct tree *root,int num)
{
    scanf("%d", &num);
    struct tree *new=(struct tree *)malloc(sizeof(struct tree));
    new->data=num;
    new->left=NULL;
    new->right=NULL;
    if(root==NULL)
        return new;
    struct tree *ptr=root,*preptr=NULL;
    while(ptr!=NULL)
    {
        preptr=ptr;
        if(num<ptr->data)
            ptr=ptr->left;
        else
            ptr=ptr->right;
    }
    if(num<preptr->data)
        preptr->left=new;
    else
        preptr->right=new;
    return root;
}
struct tree *create(struct tree *root)
{
    printf("\nMake the tree: ");
    printf("\nEnter values (enter -1 to stop): \n");
    int num,x;
    scanf("%d", &x);
    do
    {
        root=add(root,num);
        scanf("%d", &num);
    } while (num!=-1);
    return root;
}
struct tree *findMin(struct tree *node) 
{
    struct tree *current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct tree *delete(struct tree *root, int num)
{
    if(root==NULL)
    {
        printf("\nTree is empty...");
        return root;
    }
    struct tree *ptr=root, *preptr=NULL;
    if (num < root->data)
        root->left = delete(root->left, num);
    else if (num > root->data)
        root->right = delete(root->right, num);  
    else 
    {
        //Case 1: Root with 1/no child
        if (root->left == NULL) 
        {
            struct tree *temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) 
        {
            struct tree *temp = root->left;
            free(root);
            return temp;
        }
        // Case 2: Node with two children
        struct tree *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;\
}
