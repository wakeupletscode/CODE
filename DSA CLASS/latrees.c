#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree *root=NULL;
struct tree *add(struct tree *, int );
struct tree *create(struct tree *);
void inorder(struct tree *);
void preorder(struct tree *);
void postorder(struct tree *);
struct tree *delete(struct tree *, int );
int search(struct tree *, int);
int main()
{
    int ch, num, num2;
    root=create(root);
    printf("\nTree has been created...");
    printf("\n---MENU---\n");
    printf("1.Inorder\n2.Preorder\n3.Postorder\n4.Delete\n5.Search\n6.Exit\nEnter choice: ");
    do
    {
        scanf("%d", &ch);
        switch(ch)
        {
            
            case 1:
            printf("\nInorder traversal of BST: ");
            inorder(root);
            break;

            case 2:
            printf("\nPreorder traversal of BST: ");
            preorder(root);
            break;

            case 3:
            printf("\nPostorder traversal of BST: ");
            postorder(root);
            break;

            case 4:
            printf("\nEnter the number you wanna delete: ");
            scanf("%d", &num2);
            root=delete(root,num2);
            printf("\n%d has been deleted...", num2);
            break;

            case 5:
            printf("\nEnter the number you wanna search for: ");
            scanf("%d", &num);
            int a=search(root,num);
            if(a==1)
                printf("\n%d has been found...", num);
            else
                printf("\n%d has not been found...", num);
            break;

            default:
            printf("\nINVALID CHOICE\tENTER A NUMBER FROM 1-5\n");
            break;

            case 6:
            printf("\nExitting...");
        }
    } while (ch!=6);
    return 0;
}
struct tree *add(struct tree *root,int num)
{
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
    printf("\nMake the BST: ");
    printf("\nEnter values (enter -1 to stop): \n");
    int num;
    scanf("%d", &num);
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
    return root;
}
void inorder(struct tree *root)
{
    if (root==NULL) 
        return;
    inorder(root->left);
    printf("%d, ", root->data);
    inorder(root->right);
}
void preorder(struct tree *root)
{
    if (root==NULL) 
        return;
    printf("%d, ", root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct tree *root)
{
    if (root==NULL) 
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d, ", root->data);
}
int search(struct tree *root, int num)
{
    if(root==NULL)
        return 0;
    if(root->data==num)
        return 1;
    else
    {
        if(num<root->data)
            return search(root->left,num);
        if(num>root->data)
            return search(root->right,num);
    }
}