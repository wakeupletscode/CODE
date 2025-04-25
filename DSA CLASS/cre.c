#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node *next;
};

// Initialize the start pointer to NULL
struct Node *start = NULL;

// Function declarations
struct Node *create(struct Node *);
struct Node *display(struct Node *);
struct Node *insert_at_beginning(struct Node *);

int main() {
    char ch;
    do {
        printf("\n---MENU---");
        printf("\n1. Create a linked list");
        printf("\n2. Display the linked list");
        printf("\n3. Insert a node at the beginning");
        printf("\nPress any other key to exit\n");

        // Corrected scanf to use " %c" to skip any newline characters
        scanf(" %c", &ch);

        switch (ch) {
            case '1':
                start = create(start);
                printf("\nLinked list has been created\n");
                break;
            case '2':
                start = display(start);
                break;
            case '3':
                start = insert_at_beginning(start);
                printf("\nNode inserted at the beginning\n");
                break;
            default:
                printf("\nExiting...\n");
                break;
        }
    } while (ch == '1' || ch == '2' || ch == '3');

    return 0;
}

// Function to create a linked list
struct Node *create(struct Node *start) {
    struct Node *new_node, *ptr;
    int num, i = 1;

    printf("\nEnter -1 to end");
    printf("\nEnter node 1: ");
    scanf("%d", &num);

    while (num != -1) {
        // Allocate memory for a new node
        new_node = (struct Node *)malloc(sizeof(struct Node));
        if (new_node == NULL) {
            printf("\nMemory allocation failed...\n");
            return start;
        }

        new_node->data = num;
        new_node->next = NULL;  // Correctly initialize the next pointer

        if (start == NULL) {
            start = new_node;  // If the list is empty, make new node the start
        } else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;  // Traverse to the end of the list
            }
            ptr->next = new_node;  // Link the new node at the end
        }

        i++;
        printf("Enter node %d: ", i);
        scanf("%d", &num);
    }

    return start;
}

// Function to display the linked list
struct Node *display(struct Node *start) {
    struct Node *ptr;
    if (start == NULL) {
        printf("\nThe linked list is empty.\n");
        return start;
    }

    ptr = start;
    printf("\nThe linked list is: ");
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");

    return start;
}

// Function to insert a node at the beginning of the linked list
struct Node *insert_at_beginning(struct Node *start) {
    struct Node *new_node;
    int num;

    printf("\nEnter the data for the new node: ");
    scanf("%d", &num);

    // Allocate memory for a new node
    new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("\nMemory allocation failed...\n");
        return start;
    }

    new_node->data = num;
    new_node->next = start;  // New node points to the current start
    start = new_node;  // New node becomes the new start

    return start;
}
