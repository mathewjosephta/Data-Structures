#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the doubly linked list
struct Node {
    int data;
    struct Node* next;   // Pointer to the next node
    struct Node* prev;   // Pointer to the previous node
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a new node at the end of the doubly linked list
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
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

    // Link the new node at the end
    temp->next = newNode;
    newNode->prev = temp; // Set the previous pointer of newNode
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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

    // Display the doubly linked list
    displayList(head);

    return 0;
}

//SAMPLE OUTPUT
/*
How many numbers do you want to insert? 3
Enter value for node 1: 10
Enter value for node 2: 20
Enter value for node 3: 30
Doubly Linked List: 10 <-> 20 <-> 30 <-> NULL
*/
