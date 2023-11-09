#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

// Function to insert a node at a specific position in the linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    struct Node* newNode = createNode(data);
    if (position == 1) {
        newNode->next = head;
        return newNode;
    }
    struct Node* current = head;
    int count = 1;
    while (count < position - 1 && current != NULL) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Invalid position\n");
        return head;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nLinked List Operations Menu:\n");
        printf("1. Display\n");
        printf("2. Insert at the beginning\n");
        printf("3. Insert at the end\n");
        printf("4. Insert at a specific position\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display(head);
                break;
            case 2:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 3:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
