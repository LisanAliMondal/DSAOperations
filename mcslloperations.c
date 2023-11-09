#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
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

// Function to append a node to the end of a linked list
void appendNode(struct Node** head, int data) {
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
}

// Function to merge two linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* merged = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            appendNode(&merged, list1->data);
            list1 = list1->next;
        } else {
            appendNode(&merged, list2->data);
            list2 = list2->next;
        }
    }
    while (list1 != NULL) {
        appendNode(&merged, list1->data);
        list1 = list1->next;
    }
    while (list2 != NULL) {
        appendNode(&merged, list2->data);
        list2 = list2->next;
    }
    return merged;
}

// Function to concatenate two linked lists
void concatenateLists(struct Node** list1, struct Node* list2) {
    if (*list1 == NULL) {
        *list1 = list2;
    } else {
        struct Node* current = *list1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = list2;
    }
}

// Function to display a linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Append to List 1\n");
        printf("2. Append to List 2\n");
        printf("3. Merge Lists\n");
        printf("4. Concatenate Lists\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append to List 1: ");
                scanf("%d", &data);
                appendNode(&list1, data);
                printf("List 1: ");
                displayList(list1);
                break;
            case 2:
                printf("Enter data to append to List 2: ");
                scanf("%d", &data);
                appendNode(&list2, data);
                printf("List 2: ");
                displayList(list2);
                break;
            case 3:
                list1 = mergeLists(list1, list2);
                printf("Merged List: ");
                displayList(list1);
                break;
            case 4:
                concatenateLists(&list1, list2);
                printf("Concatenated List 1: ");
                displayList(list1);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
