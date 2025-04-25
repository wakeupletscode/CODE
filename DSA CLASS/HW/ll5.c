//program to insert a node at the beggining of a linked list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data) 
{
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head=newNode;
}
int main() 
{
    int n, data;
    printf("Enter no of nodes: ");
    scanf("%d", &n);
    struct Node* head = NULL, *temp = NULL;
    for(int i = 0; i < n; i++) 
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (!head) head =newNode;
        else temp->next =newNode;
        temp=newNode;
    }
    printf("Enter data to insert at the beginning: ");
    scanf("%d", &data);
    insertAtBeginning(&head, data);
    for(temp = head; temp; temp=temp->next)
        printf("%d ", temp->data);
    return 0;
}
