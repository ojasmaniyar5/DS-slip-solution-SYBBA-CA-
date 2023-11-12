#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node with the given data
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct Node *insertNode(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

// Function to count the total number of nodes in the linked list
int countNodes(struct Node *head) {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display the linked list
void displayList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to free the memory allocated for the linked list
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;
    int n, data;

    // Input the number of elements
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);

    // Input the elements from the user and create the linked list
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        head = insertNode(head, data);
    }

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    // Count and display the total number of nodes
    int totalNodes = countNodes(head);
    printf("Total Number of Nodes: %d\n", totalNodes);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
