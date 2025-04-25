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
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition(int pos);
void reverseList();
void traverseList();
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
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at position\n");
        printf("7. Reverse list\n");
        printf("8. Traverse list\n");
        printf("9. Exit\n");
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
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter pos: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                reverseList();
                break;
            case 8:
                traverseList();
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
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

    if (start == NULL) {
        new_node->prev = NULL;
        start = new_node;
    } else {
        struct Node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
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

    if (temp == NULL) 
    {
        printf("Position out of range.\n");
        free(new_node);
        return;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = new_node;
    temp->next = new_node;
    printf("Inserted at pos %d.\n", pos);
}

void deleteAtBeginning() 
{
    if (start == NULL) 
    {
        printf("List empty.\n");
        return;
    }

    struct Node *temp = start;
    start = start->next;
    if (start != NULL) {
        start->prev = NULL;
    }
    free(temp);
    printf("Deleted from beginning.\n");
}

void deleteAtEnd() 
{
    if (start == NULL) 
    {
        printf("List empty.\n");
        return;
    }
    struct Node *temp = start;
    if (temp->next == NULL) 
    {
        start = NULL;
        free(temp);
        printf("Deleted from end.\n");
        return;
    }
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Deleted from end.\n");
}

// Function to delete a node at a specific position
void deleteAtPosition(int pos) 
{
    if (start == NULL) 
    {
        printf("List empty.\n");
        return;
    }

    if (pos == 1) 
    {
        deleteAtBeginning();
        return;
    }

    struct Node *temp = start;
    for (int i = 1; i < pos && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("Position out of range.\n");
        return;
    }

    if (temp->next != NULL) 
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) 
    {
        temp->prev->next = temp->next;
    }
    free(temp);
    printf("Deleted at pos %d.\n", pos);
}

void reverseList() 
{
    struct Node *temp = NULL;
    struct Node *current = start;
    while (current != NULL) 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        start = temp->prev;
    printf("List reversed.\n");
}
// Function to traverse the list
void traverseList() 
{
    if (start == NULL) 
    {
        printf("List empty.\n");
        return;
    }
    struct Node *temp = start;
    printf("List: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
