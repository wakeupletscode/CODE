int count(struct tree* root) 
{
    if (!root)
        return 0;
    return 1 + count(root->left) + count(root->right);
}
int countleaf(struct tree* root) 
{
    if (!root)
        return 0;
    if (root->left==NULL && root->right==NULL)
        return 1;
    return count(root->left) + count(root->right);
}
int findDepth(struct tree* root) 
{
    if (root == NULL)
        return 0;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
}
// Iterative In-Order Traversal
void inOrder(struct tree* root) {
    struct Stack* stack = createStack(100); // Assuming a maximum capacity
    struct tree* current = root;

    while (current != NULL || !isEmpty(stack)) {
        while (current != NULL) {
            push(stack, current);
            current = current->left;
        }

        current = pop(stack);
        printf("%d ", current->data);
        current = current->right;
    }

    free(stack->items);
    free(stack);
}

// Iterative Pre-Order Traversal
void preOrder(struct tree* root) {
    if (root == NULL) return;
    struct Stack* stack = createStack(100); // Assuming a maximum capacity
    push(stack, root);

    while (!isEmpty(stack)) {
        struct tree* current = pop(stack);
        printf("%d ", current->data);

        // Push right child first so that left child is processed first
        if (current->right) {
            push(stack, current->right);
        }
        if (current->left) {
            push(stack, current->left);
        }
    }

    free(stack->items);
    free(stack);
}

// Iterative Post-Order Traversal
void postOrder(struct tree* root) {
    if (root == NULL) return;

    struct Stack* stack1 = createStack(100); // First stack
    struct Stack* stack2 = createStack(100); // Second stack

    push(stack1, root);

    // Process all nodes
    while (!isEmpty(stack1)) {
        struct tree* current = pop(stack1);
        push(stack2, current); // Store in second stack

        // Push left and right children to the first stack
        if (current->left) {
            push(stack1, current->left);
        }
        if (current->right) {
            push(stack1, current->right);
        }
    }

    // Print all nodes in post-order
    while (!isEmpty(stack2)) {
        struct tree* current = pop(stack2);
        printf("%d ", current->data);
    }

    free(stack1->items);
    free(stack1);
    free(stack2->items);
    free(stack2);
}
