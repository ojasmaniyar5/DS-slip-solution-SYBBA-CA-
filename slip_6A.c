#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the Binary Search Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node with the given data
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the Binary Search Tree
struct Node *insertNode(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);

    return root;
}

// Function to perform Preorder traversal of the Binary Search Tree
void preorderTraversal(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Function to perform Postorder traversal of the Binary Search Tree
void postorderTraversal(struct Node *root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Function to display the menu and perform actions based on user input
void menu() {
    struct Node *root = NULL;
    int choice, data;

    do {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert a Node\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            root = insertNode(root, data);
            break;

        case 2:
            printf("Preorder Traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;

        case 3:
            printf("Postorder Traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free allocated memory before exiting
    // Note: This is a simple example; in a real-world scenario, you might need a more comprehensive memory deallocation strategy.
    free(root);
}

// Main function to execute the program
int main() {
    menu();
    return 0;
}
