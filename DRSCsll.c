#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert a node at the end of the linked list
void append(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to reverse the linked list
void reverse() {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}

// Function to delete the first node
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
}

// Function to delete the last node
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

// Function to delete a node at a specific position
void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position == 1) {
        deleteAtBeginning();
        return;
    }

    struct Node* current = head;
    int count = 1;

    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (count < position - 1 || current->next == NULL) {
        printf("Invalid position. Node not found.\n");
        return;
    }

    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// Function to count the number of nodes in the linked list
int countNodes() {
    int count = 0;
    struct Node* current = head;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

// Function to search for an element in the linked list
int search(int key) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Element not found
}

// Function to display the linked list
void display() {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, value, position, key;

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Append\n");
        printf("2. Reverse\n");
        printf("3. Delete at Beginning\n");
        printf("4. Delete at End\n");
        printf("5. Delete at Position\n");
        printf("6. Count Nodes\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to append: ");
                scanf("%d", &value);
                append(value);
                break;
            case 2:
                reverse();
                break;
            case 3:
                deleteAtBeginning();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 6:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 7:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                position = search(key);
                if (position != -1) {
                    printf("Element found at position %d\n", position);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
