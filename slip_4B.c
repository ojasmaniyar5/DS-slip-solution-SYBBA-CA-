#include <stdio.h>

// Function to add two polynomials
void addPolynomials(int poly1[], int poly2[], int result[], int size1, int size2) {
    int i = 0, j = 0, k = 0;

    // Add corresponding terms until one polynomial is exhausted
    while (i < size1 && j < size2) {
        if (poly1[i] > poly2[j]) {
            result[k++] = poly1[i++];
        } else if (poly1[i] < poly2[j]) {
            result[k++] = poly2[j++];
        } else {
            result[k++] = poly1[i++] + poly2[j++];
        }
    }

    // Copy the remaining terms from the first polynomial, if any
    while (i < size1) {
        result[k++] = poly1[i++];
    }

    // Copy the remaining terms from the second polynomial, if any
    while (j < size2) {
        result[k++] = poly2[j++];
    }
}

// Function to display a polynomial
void displayPolynomial(int poly[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d", poly[i]);
        if (i < size - 1) {
            printf("x^%d + ", size - i - 1);
        }
    }
    printf("\n");
}

int main() {
    int size1, size2;

    // Accept the size of the first polynomial
    printf("Enter the size of the first polynomial: ");
    scanf("%d", &size1);

    // Declare an array to store the coefficients of the first polynomial
    int poly1[size1];

    // Accept the coefficients of the first polynomial
    printf("Enter the coefficients of the first polynomial (from highest to lowest degree):\n");
    for (int i = 0; i < size1; ++i) {
        printf("Coefficient for x^%d: ", size1 - i - 1);
        scanf("%d", &poly1[i]);
    }

    // Accept the size of the second polynomial
    printf("Enter the size of the second polynomial: ");
    scanf("%d", &size2);

    // Declare an array to store the coefficients of the second polynomial
    int poly2[size2];

    // Accept the coefficients of the second polynomial
    printf("Enter the coefficients of the second polynomial (from highest to lowest degree):\n");
    for (int i = 0; i < size2; ++i) {
        printf("Coefficient for x^%d: ", size2 - i - 1);
        scanf("%d", &poly2[i]);
    }

    // Determine the size of the result polynomial
    int sizeResult = (size1 > size2) ? size1 : size2;

    // Declare an array to store the coefficients of the result polynomial
    int result[sizeResult];

    // Add the two polynomials
    addPolynomials(poly1, poly2, result, size1, size2);

    // Display the original polynomials
    printf("\nFirst Polynomial: ");
    displayPolynomial(poly1, size1);
    printf("\nSecond Polynomial: ");
    displayPolynomial(poly2, size2);

    // Display the result polynomial (sum)
    printf("\nResultant Polynomial (Sum): ");
    displayPolynomial(result, sizeResult);

    return 0;
}
