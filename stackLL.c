#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Initialize a global pointer for the top of the stack
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Stack is full.\n");
        return;
    }

    newNode->data = data;
    newNode->next = top;
    top = newNode;
    printf("%d pushed onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack is empty. Nothing to pop.\n");
        return -1; // Return a sentinel value to indicate failure
    }

    struct Node* temp = top;
    int poppedValue = temp->data;
    top = temp->next;
    free(temp);
    return poppedValue;
}

// Function to display the elements in the stack
void displayStack() {
    struct Node* current = top;
    if (current == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("%d popped from the stack.\n", data);
                }
                break;
            case 3:
                displayStack();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
