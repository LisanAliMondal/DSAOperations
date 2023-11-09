#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to insert a node at a specific position in the list
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* current = *head;
    int count = 1;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        return;
    }
    newNode->prev = current;
    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

// Function to delete a node at the beginning of the list
void deleteAtBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete a node at the end of the list
void deleteAtEnd(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
}

// Function to delete a node at a specific position in the list
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    if (position < 1) {
        printf("Invalid position. Position must be >= 1.\n");
        return;
    }
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    struct Node* current = *head;
    int count = 1;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }
    if (current == NULL) {
        printf("Invalid position. Position exceeds the length of the list.\n");
        return;
    }
    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
}

// Function to print the doubly linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Any Position\n");
        printf("7. Print List\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteAtBeginning(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 7:
                printf("Doubly Linked List: ");
                printList(head);
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
