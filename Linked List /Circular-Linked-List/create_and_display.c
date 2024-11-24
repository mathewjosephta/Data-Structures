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

// Function to display a circular linked list
void displayCircularLinkedList(struct Node* head, int n) {
    struct Node* temp = head;
    for (int i = 0; i < n; i++) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("... (back to head)\n");
}

int main() {
    struct Node* head = NULL;
    int n = 5;

    createCircularLinkedList(&head, n);
    printf("Circular Linked List:\n");
    displayCircularLinkedList(head, n);

    return 0;
}
