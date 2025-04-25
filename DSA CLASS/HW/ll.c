//program to reverse a singly linked link list
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node* reverseList(struct Node* link)
{
	struct Node* prev=NULL;
	struct Node* current=link;
	struct Node* next=NULL;
	while (current!=NULL) 
    {
        next = current->next;  
        current->next =prev;  
        prev =current;   
        current =next;
    }
    return prev;
}
struct Node* createNode(int data)
{
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    {	newNode->data =data;
    	newNode->next =NULL;
    	return newNode;
    }
}
int main()
{
    int n, data;
    printf("Enter the no of nodes: ");
    scanf("%d", &n);
    printf("Enter data for node 1: ");
    scanf("%d", &data);
    struct Node* node =createNode(data);
    struct Node* temp = node;
    for(int i = 1; i < n; i++) 
    {
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);
        temp->next=createNode(data);
        temp = temp->next;
    }
	node = reverseList(node);
	temp = node;
    	while (temp!= NULL) 
        {
        	printf("%d ", temp->data);
        	temp=temp->next;
    	}
    	printf("\n");

}