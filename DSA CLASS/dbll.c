#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* create(struct Node *start);
struct Node* display(struct Node *start);
struct Node* insert_at_beginning(struct Node *start, int data);
struct Node* delete_before(struct Node *start, int data);
int main() 
{
    struct Node *start = NULL;
    int choice, data;
    do {
        printf("\n---MENU---\n");
        printf("1. Create a list\n");
        printf("2. Display the list\n");
        printf("3. Insert at the beginning\n");
        printf("4. Delete a node before a given node\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                start = create(start);
                printf("\nList created successfully.\n");
                break;
            case 2:
                start = display(start);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                start = insert_at_beginning(start, data);
                printf("Node inserted at the beginning.\n");
                break;
            case 4:
                printf("Enter the data of the node before which to delete: ");
                scanf("%d", &data);
                start = delete_before(start, data);
                printf("Node deleted before the given node.\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("WRONG CHOICE.TRY AGAIN\n");
        }
    } while (choice != 5);

    return 0;
}

struct Node* create(struct Node *start)
{
    struct Node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to exit.\n");
    printf("Enter the data: ");
    scanf("%d", &num);
    while (num != -1) {
        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = num;
        new_node->prev = NULL;
        new_node->next = NULL;

        if (start == NULL) 
        {
            start = new_node;
        } 
        else 
        {
            ptr = start;
            while (ptr->next != NULL) 
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev = ptr;
        }
        printf("Enter the data: ");
        scanf("%d", &num);
    }

    return start;
}

struct Node* display(struct Node *start) 
{
    struct Node *ptr;
    ptr = start;

    if (start == NULL) {
        printf("\nThe list is empty.\n");
        return start;
    }

    printf("\nThe list is: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return start;
}

struct Node* insert_at_beginning(struct Node *start, int data) 
{
    struct Node *new_node;
    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = start;
    if (start != NULL)
        start->prev = new_node;
    start = new_node;
    return start;
}

struct Node* delete_before(struct Node *start, int data) {
    struct Node *ptr = start, *temp;

    if (start == NULL || start->next == NULL) 
    {
        printf("\nNot enough nodes to perform this operation.\n");
        return start;
    }
    while (ptr->next != NULL && ptr->next->data != data) {
        ptr = ptr->next;
    }
    if (ptr->next == NULL) 
    {
        printf("\nNo such node found in the list.\n");
        return start;
    }
    if (ptr->prev == NULL) 
    { 
        
