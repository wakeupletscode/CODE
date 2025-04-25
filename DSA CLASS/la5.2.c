#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *start = NULL;
void insertAtBeginning(int val);
void insertAtEnd(int val);
void insertAtPosition(int val, int pos);
void createList();
void createList() 
{
    int val;
    printf("Enter values:\nEnter -1 to stop : \n");
    scanf("%d", &val);
    while (val!=-1) 
    {
        insertAtEnd(val);
        scanf("%d", &val);
    }
    printf("List created.\n");
}

int main() 
{
    int choice, val, pos;
    createList();
    do 
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter val: ");
                scanf("%d", &val);
                insertAtBeginning(val);
                break;
            case 2:
                printf("Enter val: ");
                scanf("%d", &val);
                insertAtEnd(val);
                break;
            case 3:
                printf("Enter val: ");
                scanf("%d", &val);
                printf("Enter pos: ");
                scanf("%d", &pos);
                insertAtPosition(val, pos);
                break;
            case 4:
                deleteAtBeginning();
                break;
            
    } while (choice != 9);
    return 0;
}

void insertAtBeginning(int val) 
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->prev = NULL;
    new_node->next = start;
    if (start != NULL) 
        start->prev = new_node;
    start = new_node;
    printf("Inserted at beginning.\n");
}

void insertAtEnd(int val) 
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    if (start == NULL) 
    {
        new_node->prev = NULL;
        start = new_node;
    } 
    else 
    {
        struct Node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
    }
    printf("Inserted at end.\n");
}

void insertAtPosition(int val, int pos) 
{
    if (pos == 1) 
    {
        insertAtBeginning(val);
        return;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    struct Node *temp = start;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) 
        temp = temp->next;

