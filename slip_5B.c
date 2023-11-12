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

// Function to create a linked list with individual digits of a given number
struct Node *createListFromNumber(int number) {
    struct Node *head = NULL;

    // Special case for handling the number 0
    if (number == 0) {
        return insertNode(head, 0);
    }

    // Extract individual digits and insert into the linked list
    while (number > 0) {
        int digit = number % 10;
        head = insertNode(head, digit);
        number /= 10;
    }

    // Reverse the list to maintain the order of digits
    struct Node *prev = NULL, *current = head, *next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    return head;
}

// Main function to execute the program
int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Create a linked list from the individual digits of the number
    struct Node *head = createListFromNumber(number);

    // Display the linked list
    printf("Linked List: ");
    displayList(head);

    // Free the memory allocated for the linked list
    freeList(head);

    return 0;
}
