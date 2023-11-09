#include <stdio.h>
#include <stdlib.h>

// Define a structure for a linked list node
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of a linked list
void insertEnd(struct Node** head, int data) {
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

// Function to display a linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to merge two linked lists
struct Node* mergeLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            insertEnd(&mergedList, list1->data);
            list1 = list1->next;
        } else {
            insertEnd(&mergedList, list2->data);
            list2 = list2->next;
        }
    }

    // Append remaining elements from list1
    while (list1 != NULL) {
        insertEnd(&mergedList, list1->data);
        list1 = list1->next;
    }

    // Append remaining elements from list2
    while (list2 != NULL) {
        insertEnd(&mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
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

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;
    int choice, data;

    do {
        printf("Menu:\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Merge Lists\n");
        printf("6. Concatenate Lists (List 1 + List 2)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert into List 1: ");
                scanf("%d", &data);
                insertEnd(&list1, data);
                break;
            case 2:
                printf("Enter data to insert into List 2: ");
                scanf("%d", &data);
                insertEnd(&list2, data);
                break;
            case 3:
                printf("List 1: ");
                displayList(list1);
                break;
            case 4:
                printf("List 2: ");
                displayList(list2);
                break;
            case 5:
                mergedList = mergeLists(list1, list2);
                printf("Merged List: ");
                displayList(mergedList);
                break;
            case 6:
                concatenateLists(&list1, list2);
                printf("Concatenated List (List 1 + List 2): ");
                displayList(list1);
                list2 = NULL; // Reset list2 after concatenation
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    // Free memory
    while (list1 != NULL) {
        struct Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        struct Node* temp = list2;
        list2 = list2->next;
        free(temp);
    }
    free(mergedList);

    return 0;
}
