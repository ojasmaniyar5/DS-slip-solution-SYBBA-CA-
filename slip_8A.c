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

// Function to search for a node with the given data in the Binary Search Tree
struct Node *searchNode(struct Node *root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return searchNode(root->left, data);

    return searchNode(root->right, data);
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
    int choice, data, searchData;
    struct Node *searchResult;

    do {
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert a Node\n");
        printf("2. Display (Inorder Traversal)\n");
        printf("3. Search for an Element\n");
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
            printf("Enter data to search: ");
            scanf("%d", &searchData);
            searchResult = searchNode(root, searchData);
            if (searchResult != NULL)
                printf("Element %d found in the Binary Search Tree.\n", searchData);
            else
                printf("Element %d not found in the Binary Search Tree.\n", searchData);
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
