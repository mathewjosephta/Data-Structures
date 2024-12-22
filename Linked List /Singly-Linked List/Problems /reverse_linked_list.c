#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* reverseListIterative(Node* head) {
    Node* prev = NULL;
    Node* current = head;

    while (current) {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

Node* reverseListRecursive(Node* head) {
    if (!head || !head->next) return head;

    Node* rest = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);

    printf("Original List: ");
    printList(head);

    head = reverseListIterative(head);
    printf("List after Iterative Reverse: ");
    printList(head);

    head = reverseListRecursive(head);
    printf("List after Recursive Reverse: ");
    printList(head);

    return 0;
}
