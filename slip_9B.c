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

// Function to reverse a singly linked list
struct Node *reverseList(struct Node *head) {
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev; // new head of the reversed list
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

    // Display the original linked list
    printf("Original Linked List: ");
    displayList(head);

    // Reverse the linked list
    head = reverseList(head);

    // Display the reversed linked list
    printf("Reversed Linked List: ");
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
