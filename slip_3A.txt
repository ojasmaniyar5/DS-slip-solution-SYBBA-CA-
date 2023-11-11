#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node in the singly linked list
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the singly linked list
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty, make the new node the head
    if (head == NULL) {
        head = newNode;
    } else {
        // Traverse to the end of the list
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Insert the new node at the end
        temp->next = newNode;
    }

    return head;
}

// Function to display the singly linked list
void displayList(struct Node* head) {
    // If the list is empty, print a message
    if (head == NULL) {
        printf("Linked List is empty.\n");
        return;
    }

    struct Node* temp = head;

    // Traverse the singly linked list and print the elements
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Function to find the union of two sorted linked lists
struct Node* findUnion(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* tail = NULL;

    // Traverse both lists simultaneously
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            if (result == NULL) {
                result = tail = createNode(list1->data);
            } else {
                tail->next = createNode(list1->data);
                tail = tail->next;
            }
            list1 = list1->next;
        } else if (list1->data > list2->data) {
            if (result == NULL) {
                result = tail = createNode(list2->data);
            } else {
                tail->next = createNode(list2->data);
                tail = tail->next;
            }
            list2 = list2->next;
        } else {
            // If the elements are equal, add either one to the result
            if (result == NULL) {
                result = tail = createNode(list1->data);
            } else {
                tail->next = createNode(list1->data);
                tail = tail->next;
            }
            list1 = list1->next;
            list2 = list2->next;
        }
    }

    // Add the remaining elements of list1, if any
    while (list1 != NULL) {
        tail->next = createNode(list1->data);
        tail = tail->next;
        list1 = list1->next;
    }

    // Add the remaining elements of list2, if any
    while (list2 != NULL) {
        tail->next = createNode(list2->data);
        tail = tail->next;
        list2 = list2->next;
    }

    return result;
}

// Main function to test the program
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first linked list
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);

    // Insert elements into the second linked list
    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 3);
    list2 = insertEnd(list2, 4);

    // Display the first linked list
    printf("Linked List 1: ");
    displayList(list1);

    // Display the second linked list
    printf("Linked List 2: ");
    displayList(list2);

    // Find and display the union of the linked lists
    struct Node* unionList = findUnion(list1, list2);
    printf("Union of Linked Lists: ");
    displayList(unionList);

    return 0;
}
