#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    int items[MAX_STACK_SIZE];
};

// Function to initialize an empty stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(struct Stack *stack, int value) {
    if (stack->top == MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    } else {
        stack->items[++stack->top] = value;
    }
}

// Function to pop an item from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    } else {
        return stack->items[stack->top--];
    }
}

// Function to evaluate a postfix expression using a stack
int evaluatePostfix(char *expression, int values[]) {
    struct Stack stack;
    initializeStack(&stack);

    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] >= 'a' && expression[i] <= 'z') {
            // Operand (variable)
            push(&stack, values[expression[i] - 'a']);
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // Operator
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (expression[i]) {
            case '+':
                push(&stack, operand1 + operand2);
                break;
            case '-':
                push(&stack, operand1 - operand2);
                break;
            case '*':
                push(&stack, operand1 * operand2);
                break;
            case '/':
                push(&stack, operand1 / operand2);
                break;
            }
        }
        i++;
    }

    return pop(&stack);
}

int main() {
    char postfixExpression[] = "ab+cd-*";
    int values[26]; // Assuming variables are lowercase letters

    // Input values for variables
    printf("Enter values for variables (a, b, c, ...):\n");
    for (char variable = 'a'; variable <= 'z'; variable++) {
        printf("%c = ", variable);
        scanf("%d", &values[variable - 'a']);
    }

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfixExpression, values);

    // Display the result
    printf("Result: %d\n", result);

    return 0;
}
