#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

int stack[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int item) {
    if (top == MAX_SIZE - 1) {
        printf("Stack is full. Cannot push element.\n");
    } else {
        stack[++top] = item;
        printf("%d pushed onto the stack.\n", item);
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1; // Return a sentinel value to indicate failure
    } else {
        return stack[top--];
    }
}

// Function to display the elements in the stack
void displayStack() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push element onto stack\n");
        printf("2. Pop element from stack\n");
        printf("3. Display stack elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                item = pop();
                if (item != -1) {
                    printf("%d popped from the stack.\n", item);
                }
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
