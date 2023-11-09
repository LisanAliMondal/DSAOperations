#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void enqueue(struct Node** front, struct Node** rear, int value);
int dequeue(struct Node** front, struct Node** rear);
void display(struct Node* front);
void menu();

int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;
            case 2:
                value = dequeue(&front, &rear);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;
            case 3:
                display(front);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}

// Function to enqueue an element
void enqueue(struct Node** front, struct Node** rear, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }

    printf("Enqueued element: %d\n", value);
}

// Function to dequeue an element
int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    struct Node* temp = *front;
    int value = temp->data;

    *front = (*front)->next;

    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);

    return value;
}

// Function to display the elements in the queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (front != NULL) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

// Function to display the menu
void menu() {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
}
