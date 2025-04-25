#include<stdio.h>
#include<stdlib.h>  // Changed to stdlib.h for malloc

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;  // Initialize start pointer to NULL

// Function declarations
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_list(struct node *);

int main() {
    int option;

    do {
        printf("\n****MAIN MENU****");
        printf("\n 1. Create linked list");
        printf("\n 2. Display linked list");
        printf("\n 3. Delete the entire list");
        printf("\n 4. Exit");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                start = create_ll(start);
                printf("\nLinked list created\n");
                break;

            case 2:
                start = display(start);
                break;

            case 3:
                start = delete_list(start);
                printf("\nLinked list deleted\n");
                break;

            case 4:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid option! Please try again.\n");
        }
    } while (option != 4);

    return 0;
}

// Function to create a linked list
struct node *create_ll(struct node *start) {
    struct node *new_node, *ptr;
    int num;
    printf("\nEnter -1 to end");
    printf("\nEnter the data: ");
    scanf("%d", &num);

    while (num != -1) {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        new_node->next = NULL;

        if (start == NULL) {
            start = new_node;  // If the list is empty, make the new node the start
        } else {
            ptr = start;
            while (ptr->next != NULL) {  // Traverse to the last node
                ptr = ptr->next;
            }
            ptr->next = new_node;  // Link the last node to the new node
        }
        printf("\nEnter the data: ");
        scanf("%d", &num);
    }
    return start;
}

// Function to display the linked list
struct node *display(struct node *start) {
    struct node *ptr;
    ptr = start;

    if (start == NULL) {
        printf("\nList is empty\n");
        return start;
    }

    while (ptr != NULL) 
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
    return start;
}

// Function to delete the node at the beginning of the list
struct node *delete_beg(struct node *start) {
    struct node *ptr;
    /*if (start == NULL) {
        printf("\nList is already empty\n");
        return start;
    }*/
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

// Function to delete the entire list
struct node *delete_list(struct node *start)
{
    while (start != NULL) 
    {
        start = delete_beg(start);
    }
    printf("\nAll nodes have been deleted.\n");
    return start;
}