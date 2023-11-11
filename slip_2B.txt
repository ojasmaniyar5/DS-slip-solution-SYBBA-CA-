#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node in the circular doubly linked list
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the end of the circular doubly linked list
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
        head->next = head->prev = head; // Circular doubly linked list
    } else {
        // Traverse to the end of the list
        struct Node* last = head->prev;

        // Insert the new node at the end
        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }

    return head;
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    // If the list is empty, print a message
    if (head == NULL) {
        printf("Circular Doubly Linked List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Traverse the circular doubly linked list and print the elements
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head); // Continue until we reach the head again

    printf("(head)\n");
}

// Main function to test the circular doubly linked list
int main() {
    struct Node* head = NULL;

    // Insert elements into the circular doubly linked list
    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    head = insertEnd(head, 4);

    // Display the circular doubly linked list
    printf("Circular Doubly Linked List: ");
    displayList(head);

    return 0;
}
