#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a circular linked list
void createCircularLinkedList(struct Node** head, int n) {
    struct Node *temp, *newNode;
    *head = (struct Node*)malloc(sizeof(struct Node));
    (*head)->data = 1;
    (*head)->next = NULL;
    temp = *head;

    for (int i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = *head;  // Make the list circular
}

// Function to search for an element in the circular linked list
int search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;

    if (head == NULL) return -1;  // Empty list

    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    return -1;  // Key not found
}

// Function to traverse and display the list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("... (back to head)\n");
}

int main() {
    struct Node* head = NULL;
    int n = 5, key = 3;

    // Create a circular linked list with 5 nodes
    createCircularLinkedList(&head, n);

    // Traverse and display the list
    printf("Created Circular Linked List:\n");
    traverse(head);

    // Search for a key in the list
    int position = search(head, key);
    if (position != -1) {
        printf("Element %d found at position %d.\n", key, position);
    } else {
        printf("Element %d not found in the list.\n", key);
    }

    return 0;
}
