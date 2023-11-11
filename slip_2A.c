#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50

// Structure to represent a stack
struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an item onto the stack
void push(struct Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push %c onto the stack.\n", item);
    } else {
        stack->items[++stack->top] = item;
    }
}

// Function to pop an item from the stack
char pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return '\0';
    } else {
        return stack->items[stack->top--];
    }
}

// Function to reverse a string using a stack
void reverseString(struct Stack *stack, char *str) {
    // Push each character of the string onto the stack
    for (int i = 0; i < strlen(str); ++i) {
        push(stack, str[i]);
    }

    // Pop each character from the stack to reverse the string
    for (int i = 0; i < strlen(str); ++i) {
        str[i] = pop(stack);
    }
}

int main() {
    struct Stack stack;
    initialize(&stack);

    char inputString[MAX_SIZE];

    // Accept a string from the user
    printf("Enter a string: ");
    fgets(inputString, MAX_SIZE, stdin);
    inputString[strcspn(inputString, "\n")] = '\0';  // Remove the newline character

    // Reverse the string using the stack
    reverseString(&stack, inputString);

    // Display the reversed string
    printf("Reversed string: %s\n", inputString);

    return 0;
}
