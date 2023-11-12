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

// Function to find the minimum value node in a BST
struct Node *findMinNode(struct Node *root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to delete a node with the given data from the Binary Search Tree
struct Node *deleteNode(struct Node *root, int data) {
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct Node *temp = findMinNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to display the Binary Search Tree (Inorder traversal)
void displayInorder(struct Node *root) {
    if (root != NULL) {
        displayInorder(root->left);
        printf("%d ", root->data);
        displayInorder(root->right);
    }
}

// Function to display the menu and perform actions based on user input
void menu() {
    struct Node *root = NULL;
    int choice, data;

    do {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert a Node\n");
        printf("2. Display (Inorder Traversal)\n");
        printf("3. Delete a Node\n");
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
            printf("Display (Inorder Traversal): ");
            displayInorder(root);
            printf("\n");
            break;

        case 3:
            printf("Enter data to delete: ");
            scanf("%d", &data);
            root = deleteNode(root, data);
            printf("Node with data %d deleted.\n", data);
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
