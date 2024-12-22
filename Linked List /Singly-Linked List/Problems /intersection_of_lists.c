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

int getCount(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

Node* getIntersectionNode(Node* head1, Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);

    int diff = abs(c1 - c2);
    Node* longer = c1 > c2 ? head1 : head2;
    Node* shorter = c1 > c2 ? head2 : head1;

    for (int i = 0; i < diff; i++) {
        longer = longer->next;
    }

    while (longer && shorter) {
        if (longer == shorter) {
            return longer;
        }
        longer = longer->next;
        shorter = shorter->next;
    }

    return NULL;
}

int main() {
    Node* head1 = createNode(1);
    head1->next = createNode(2);
    head1->next->next = createNode(3);

    Node* head2 = createNode(10);
    head2->next = head1->next;

    Node* intersection = getIntersectionNode(head1, head2);

    if (intersection) {
        printf("Intersection point data: %d\n", intersection->data);
    } else {
        printf("No intersection point found.\n");
    }

    return 0;
}
