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

// Function to calculate the height of the Binary Search Tree
int treeHeight(struct Node *root) {
    if (root == NULL)
        return 0;

    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);

    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Function to print nodes at the given level in the Binary Search Tree
void printLevel(struct Node *root, int level) {
    if (root == NULL)
        return;

    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Function to display the Binary Search Tree level-wise
void displayLevelOrder(struct Node *root) {
    int height = treeHeight(root);
    for (int i = 1; i <= height; i++) {
        printf("Level %d: ", i);
        printLevel(root, i);
        printf("\n");
    }
}

// Function to free the memory allocated for the Binary Search Tree
void freeTree(struct Node *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node *root = NULL;
    int n, data;

    // Input the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Input the elements from the user and create the Binary Search Tree
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // Display the Binary Search Tree level-wise
    printf("\nBinary Search Tree Level-wise:\n");
    displayLevelOrder(root);

    // Free the memory allocated for the Binary Search Tree
    freeTree(root);

    return 0;
}
