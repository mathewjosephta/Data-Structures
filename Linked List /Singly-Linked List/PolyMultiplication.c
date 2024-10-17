#include <stdio.h>
#include <stdlib.h>

// Define a structure for a term in the polynomial
typedef struct Term {
    int coeff;
    int exp;
    struct Term *next;
} Term;

// Function to insert a new term into a polynomial
void insertTerm(Term **poly, int coeff, int exp) {
    Term *newTerm = (Term *)malloc(sizeof(Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;

    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        Term *temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}

// Function to multiply two polynomials
Term* multiplyPolynomials(Term *poly1, Term *poly2) {
    Term *result = NULL;
    Term *temp1 = poly1;
    
    while (temp1 != NULL) {
        Term *temp2 = poly2;
        while (temp2 != NULL) {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insertTerm(&result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    
    return result;
}

// Function to display a polynomial
void displayPolynomial(Term *poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d ", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

// Function to free memory allocated for polynomial
void freePolynomial(Term *poly) {
    Term *temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    Term *poly1 = NULL;
    Term *poly2 = NULL;
    Term *result = NULL;

    // Example polynomials
    insertTerm(&poly1, 3, 2);  // 3x^2
    insertTerm(&poly1, 5, 1);  // 5x^1
    insertTerm(&poly1, 2, 0);  // 2x^0

    insertTerm(&poly2, 4, 1);  // 4x^1
    insertTerm(&poly2, 1, 0);  // 1x^0

    // Display polynomials
    printf("First polynomial: ");
    displayPolynomial(poly1);

    printf("Second polynomial: ");
    displayPolynomial(poly2);

    // Multiply polynomials
    result = multiplyPolynomials(poly1, poly2);
    
    // Display result
    printf("Result of multiplication: ");
    displayPolynomial(result);

    // Free allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
