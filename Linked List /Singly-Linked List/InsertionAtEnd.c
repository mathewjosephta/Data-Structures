#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
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

    // Insert the new node at the end
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int n, value;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i+1);
        scanf("%d", &value);
        insertAtEnd(&head, value);
    }

    printf("Linked List: ");
    displayList(head);

    return 0;
}

//SAMPLE OUTPUT
/*
Enter the number of elements to insert: 4
Enter value for node 1: 10
Enter value for node 2: 20
Enter value for node 3: 30
Enter value for node 4: 40
Linked List: 10 -> 20 -> 30 -> 40 -> NULL

*/
