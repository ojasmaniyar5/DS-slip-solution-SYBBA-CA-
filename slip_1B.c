#include <stdio.h>

// Function to evaluate a polynomial given its coefficients and the value of x
double evaluatePolynomial(double coefficients[], int degree, double x) {
    double result = 0.0;

    // Iterate through the coefficients and evaluate the polynomial
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * pow(x, degree - i);
    }

    return result;
}

int main() {
    int degree;

    // Get the degree of the polynomial from the user
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    // Declare an array to store the coefficients
    double coefficients[degree + 1];

    // Get the coefficients from the user
    printf("Enter the coefficients of the polynomial (from highest to lowest degree):\n");
    for (int i = degree; i >= 0; --i) {
        printf("Coefficient for x^%d: ", i);
        scanf("%lf", &coefficients[i]);
    }

    double x;

    // Get the value of x from the user
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // Evaluate the polynomial and display the result
    double result = evaluatePolynomial(coefficients, degree, x);
    printf("Result of the polynomial for x = %.2lf is: %.2lf\n", x, result);

    return 0;
}
