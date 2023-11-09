#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Point to itself if the list is empty
    } else {
        newNode->next = head->next;
        head->next = newNode;
    }
    return newNode; // Return the new head
}

// Function to insert a node at the end of the circular linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Point to itself if the list is empty
        return newNode; // Return the new head
    }
    newNode->next = head->next;
    head->next = newNode;
    return head; // Return the same head
}

// Function to insert a node at any position in the circular linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position. Position should be greater than 0.\n");
        return head;
    }

    struct Node* newNode = createNode(data);
    if (head == NULL) {
        newNode->next = newNode; // Point to itself if the list is empty
        return newNode; // Return the new head
    }

    struct Node* current = head;
    while (position > 1 && current->next != head) {
        current = current->next;
        position--;
    }

    newNode->next = current->next;
    current->next = newNode;
    if (position == 1) {
        return newNode; // Update the head if inserted at the beginning
    } else {
        return head; // Return the same head
    }
}

// Function to delete a node from the beginning of the circular linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* temp = head->next;
    if (temp == head) {
        free(temp);
        return NULL; // List becomes empty
    }

    head->next = temp->next;
    free(temp);
    return head; // Return the new head
}

// Function to delete a node from the end of the circular linked list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != head) {
        prev = current;
        current = current->next;
    }

    prev->next = head;
    free(current);

    if (prev == NULL) {
        return NULL; // List becomes empty
    }

    return head; // Return the same head
}

// Function to delete a node from any position in the circular linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return NULL;
    }

    if (position <= 0) {
        printf("Invalid position. Position should be greater than 0.\n");
        return head;
    }

    if (position == 1) {
        return deleteAtBeginning(head); // Use the existing function for deletion
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    int currentPos = 1;

    while (currentPos < position && current->next != head) {
        prev = current;
        current = current->next;
        currentPos++;
    }

    if (currentPos < position) {
        printf("Position exceeds the length of the list. Cannot delete.\n");
        return head;
    }

    prev->next = current->next;
    free(current);

    return head;
}

// Function to display the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nCircular Linked List Operations\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at any position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at any position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
