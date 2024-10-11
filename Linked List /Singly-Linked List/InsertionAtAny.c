#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at a specific position
void insertAtPosition(struct Node** head, int value, int position) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // If inserting at the head (position 0)
    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse to the node just before the desired position
    struct Node* temp = *head;
    for (int i = 0; i < position - 1; i++) {
        // If the position is greater than the list length, exit
        if (temp == NULL) {
            printf("Position out of bounds!\n");
            free(newNode);  // Free the newly created node if not used
            return;
        }
        temp = temp->next;
    }

    // Insert the new node at the desired position
    newNode->next = temp->next;
    temp->next = newNode;
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
    int n, value, position;

    printf("How many numbers do you want to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        printf("Enter position to insert (0 for front): ");
        scanf("%d", &position);
        insertAtPosition(&head, value, position);
    }

    printf("The linked list is: ");
    displayList(head);

    return 0;
}

//SAMPLE OUTPUT
/*
How many numbers do you want to insert? 4
Enter value for node 1: 25
Enter position to insert (0 for front): 0
Enter value for node 2: 30
Enter position to insert (0 for front): 1
Enter value for node 3: 20
Enter position to insert (0 for front): 1
Enter value for node 4: 10
Enter position to insert (0 for front): 3
The linked list is: 25 -> 20 -> 30 -> 10 -> NULL
*/
