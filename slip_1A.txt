#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node in the Binary Search Tree
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new element into the Binary Search Tree
struct Node* insertElement(struct Node* root, int value) {
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

// Function to display the elements of the Binary Search Tree (in-order traversal)
void displayBST(struct Node* root) {
    if (root != NULL) {
        displayBST(root->left);
        printf("%d ", root->data);
        displayBST(root->right);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create a Binary Search Tree\n");
    printf("2. Insert element in Binary Search Tree\n");
    printf("3. Display Binary Search Tree\n");
    printf("4. Exit\n");
}

// Main function
int main() {
    struct Node* root = NULL;
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
                // Insert element in Binary Search Tree
                printf("Enter the element to insert: ");
                scanf("%d", &value);
                root = insertElement(root, value);
                printf("%d inserted into the Binary Search Tree.\n", value);
                break;

            case 3:
                // Display Binary Search Tree
                printf("Binary Search Tree: ");
                displayBST(root);
                printf("\n");
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
