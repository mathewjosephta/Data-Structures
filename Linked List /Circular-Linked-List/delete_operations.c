#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to delete the first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    if ((*head)->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    struct Node* last = *head;
    while (last->next != *head) {
        last = last->next;
    }

    *head = (*head)->next;
    last->next = *head;
    free(temp);
}

// Function to delete the last node
void deleteLast(struct Node** head) {
    if (*head == NULL) return;

    struct Node* temp = *head;
    if ((*head)->next == *head) {
        *head = NULL;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    while (temp->next != *head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
}

// Display the circular linked list
void display(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) return;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("... (back to head)\n");
}

int main() {
    struct Node* head = NULL;

    // Example: Create a circular linked list and delete nodes
    // Implement the createCircularLinkedList function as needed
    // Then test deleteFirst and deleteLast

    return 0;
}
