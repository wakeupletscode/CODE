#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node* creat(int data);
void display(struct node* start);
struct node* add(struct node* start, int data, int pos);
struct node* delete(struct node* start, int pos);
struct node* reverse(struct node* start);

int main() 
{
    struct node *start = NULL;
    int choice, data, pos;
    do {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Add nod\n");
        printf("3. Delete node\n");
        printf("4. Reverse the list\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                display(start);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter element: ");
                scanf("%d", &data);
                start = add(start, data, pos);
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                start = delete(start, pos);
                break;
            case 4:
                start = reverse(start);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}
struct node* creat(int data) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}
void display(struct node* start) 
{
    if (start == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = start;
    printf("Doubly Linked List: ");
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
struct node* add(struct node* start, int data, int pos) 
{
    struct node* new_node = creat(data);
    if (pos == 1) 
    {
        if (start != NULL) 
        {
            start->prev = new_node;
        }
        new_node->next = start;
        start = new_node;
    } 
    else 
    {
        struct node* temp = start;
        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL) 
        {
            printf("out of bounds.\n");
            return start;
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = new_node;
        temp->next = new_node;
    }
    return start;
}
struct node* delete(struct node* start, int pos) 
{
    if (start == NULL) 
    {
        printf("List is empty.\n");
        return start;
    }
    struct node* temp = start;
    if (pos == 1) 
    {
        start = temp->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    } 
    else 
    {
        for (int i = 1; i < pos && temp != NULL; i++)
            temp = temp->next;
        if (temp == NULL) 
        {
            printf("out of bounds.\n");
            return start;
        }
        if (temp->prev != NULL) 
            temp->prev->next = temp->next;
        if (temp->next != NULL) 
            temp->next->prev = temp->prev;
        free(temp);
    }
    return start;
}

struct node* reverse(struct node* start) 
{
    struct node* temp = NULL;
    struct node* current = start;
    while (current != NULL) 
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        start = temp->prev;
    return start;
}
