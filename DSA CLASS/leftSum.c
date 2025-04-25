#include<stdio.h>
#include<stdlib.h>
struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
};
struct tree* create(int val)
{
    struct tree *new=(struct tree *)malloc(sizeof(struct tree));
    new->data=val;
    new->left=NULL;
    new->right=NULL;
    return new;
}
int isLeaf(struct tree *node)
{
    return node && !node->left && !node->right;
}
int sumOfLeftLeaves(struct tree *root) 
{
    int s=0;
    if(!root)
        return 0;
    if(isLeaf(root->left))
        s+=root->left->data;
    s+=sumOfLeftLeaves(root->left);
    s+=sumOfLeftLeaves(root->right);
    return s;
}