#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the Binary Search Tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node in the Binary Search Tree
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new element into the Binary Search Tree
struct Node *insertElement(struct Node *root, int value) {
    // If the tree is empty, create a new node
    if (root == NULL) {
        return createNode(value);
    }

    // Otherwise, recur down the tree
    if (value < root->data) {
        root->left = insertElement(root->left, value);
    } else if (value > root->data) {
        root->right = insertElement(root->right, value);
    }

    // Return the unchanged root pointer
    return root;
}

// Function to perform Inorder traversal of the Binary Search Tree
void inorderTraversal(struct Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
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

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create a Binary Search Tree\n");
    printf("2. Traverse the BST (Inorder)\n");
    printf("3. Traverse the BST (Postorder)\n");
    printf("4. Exit\n");
}

// Main function
int main() {
    struct Node *root = NULL;
    int choice, value;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Create a Binary Search Tree
                root = NULL; // Reset the tree
                printf("Binary Search Tree created.\n");
                break;

            case 2:
                // Traverse the BST (Inorder)
                if (root == NULL) {
                    printf("Binary Search Tree is empty.\n");
                } else {
                    printf("Inorder Traversal: ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;

            case 3:
                // Traverse the BST (Postorder)
                if (root == NULL) {
                    printf("Binary Search Tree is empty.\n");
                } else {
                    printf("Postorder Traversal: ");
                    postorderTraversal(root);
                    printf("\n");
                }
                break;

            case 4:
                // Exit
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
