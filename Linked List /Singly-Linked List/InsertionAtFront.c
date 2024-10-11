#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the front of the list
void insertAtFront(struct Node** head, int value) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;  // Point new node's next to the current head

    // Update head to point to the new node
    *head = newNode;
}

// Function to display the list
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

    printf("How many numbers do you want to insert at the front? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insertAtFront(&head, value);
    }

    printf("The linked list is: ");
    displayList(head);

    return 0;
}

//SAMPLE OUTPUT
/*
How many numbers do you want to insert at the front? 3
Enter value for node 1: 30
Enter value for node 2: 20
Enter value for node 3: 10
The linked list is: 10 -> 20 -> 30 -> NULL
*/
