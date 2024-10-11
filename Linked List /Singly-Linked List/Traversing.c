#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Add the new node at the end
    temp->next = newNode;
}

// Function to traverse and display the list
void traverseList(struct Node* head) {
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;  // Move to the next node
    }
    printf("NULL\n");  // Indicate the end of the list
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("How many numbers do you want to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    // Call the function to traverse and display the linked list
    traverseList(head);

    return 0;
}

//SAMPLE OUTPUT
/*
How many numbers do you want to insert? 3
Enter value for node 1: 10
Enter value for node 2: 20
Enter value for node 3: 30
Linked List: 10 -> 20 -> 30 -> NULL
*/
