#include <stdio.h>
#include <stdlib.h>

// Define a structure for a polynomial term
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term in the polynomial
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* term = (struct Term*)malloc(sizeof(struct Term));
    if (term == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    term->coefficient = coefficient;
    term->exponent = exponent;
    term->next = NULL;
    return term;
}

// Function to insert a term at the end of a polynomial
void insertTerm(struct Term** poly, int coefficient, int exponent) {
    struct Term* newTerm = createTerm(coefficient, exponent);
    if (*poly == NULL) {
        *poly = newTerm;
    } else {
        struct Term* current = *poly;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newTerm;
    }
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum_coefficient = poly1->coefficient + poly2->coefficient;
            if (sum_coefficient != 0) {
                insertTerm(&result, sum_coefficient, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Append any remaining terms from poly1 and poly2
    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to free memory used by a polynomial
void freePolynomial(struct Term* poly) {
    struct Term* current = poly;
    while (current != NULL) {
        struct Term* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result;

    // Input the first polynomial
    int n, coefficient, exponent;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }

    // Input the second polynomial
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n);
    printf("Enter the coefficients and exponents for each term:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }

    // Add the polynomials and display the result
    result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    // Free allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(result);

    return 0;
}
