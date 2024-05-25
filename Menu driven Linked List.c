#include <stdio.h>
#include <stdlib.h>

// Define the structure for the doubly linked list node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function prototypes
void insertAtBeginning(struct Node** head_ref, int new_data);
void insertAtEnd(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void deleteNode(struct Node** head_ref, int key);
void deleteAtPosition(struct Node** head_ref, int position);
void printList(struct Node* node);
void menu();

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position (0-based index): ");
                scanf("%d", &position);
                if (position == 0) {
                    insertAtBeginning(&head, data);
                } else {
                    struct Node* temp = head;
                    for (int i = 0; i < position-1 && temp != NULL; i++) {
                        temp = temp->next;
                    }
                    if (temp == NULL) {
                        printf("Position out of range\n");
                    } else {
                        insertAfter(temp, data);
                    }
                }
                break;
            case 4:
                printf("Enter key to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 5:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 6:
                printList(head);
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

// Function to insert a new node at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    new_node->prev = last;
}

// Function to insert a new node after a given node
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    new_node->prev = prev_node;
    prev_node->next = new_node;

    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

// Function to delete a node by key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (*head_ref == temp) {
        *head_ref = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to delete a node by position
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        return;
    }

    struct Node* temp = *head_ref;

    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (*head_ref == temp) {
        *head_ref = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

// Function to print the linked list
void printList(struct Node* node) {
    struct Node* last;
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf("%d -> ", node->data);
        last = node;
        node = node->next;
    }
    printf("NULL\n");

    printf("Traversal in reverse direction:\n");
    while (last != NULL) {
        printf("%d -> ", last->data);
        last = last->prev;
    }
    printf("NULL\n");
}

// Function to display the menu
void menu() {
    printf("\nMenu:\n");
    printf("1. Insert at Beginning\n");
    printf("2. Insert at End\n");
    printf("3. Insert at Position\n");
    printf("4. Delete by Key\n");
    printf("5. Delete by Position\n");
    printf("6. Print List\n");
    printf("7. Exit\n");
}