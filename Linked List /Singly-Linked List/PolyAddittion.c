#include <stdio.h>
#include <stdlib.h>

// Define a node structure for polynomial terms
struct Node {
    int coefficient;  // Coefficient of the term
    int exponent;     // Exponent of the term
    struct Node* next; // Pointer to the next term
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term in a polynomial linked list
void insertTerm(struct Node** head, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    struct Node* temp = *head;

    // If the list is empty or the new term has a higher exponent than the head
    if (*head == NULL || exponent > (*head)->exponent) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Traverse the list to find the correct position to insert
    while (temp->next != NULL && temp->next->exponent > exponent) {
        temp = temp->next;
    }

    // If the term with the same exponent already exists, add coefficients
    if (temp->exponent == exponent) {
        temp->coefficient += coefficient;
        free(newNode); // Free the new node since it's not needed
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to add two polynomial linked lists
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL || poly2 != NULL) {
        if (poly1 == NULL) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent == poly2->exponent) {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
    }

    return result;
}

// Function to display a polynomial linked list
void displayPolynomial(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* result = NULL;

    // Polynomial 1: 3x^2 + 5x + 2
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 5, 1);
    insertTerm(&poly1, 2, 0);

    // Polynomial 2: 4x^2 + 1
    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);
    
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}

//SAMPLE OUTPUT
/*
Polynomial 1: 3x^2 + 5x + 2
Polynomial 2: 4x^2 + 1
Resultant Polynomial: 7x^2 + 5x + 3
*/
