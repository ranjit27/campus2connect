#include <stdio.h>

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main() {
    int choice;
    double num1, num2, result;

    while (1) {
     
        printf("\n Calculator\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting the calculator. Goodbye!\n");
            break;
        }
        printf("Enter two numbers: ");
        scanf("%lf %lf", &num1, &num2);
        switch (choice) {
            case 1:
                result = add(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                result = subtract(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                result = multiply(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                if (num2 != 0) {
                    result = divide(num1, num2);
                    printf("Result: %.2lf\n", result);
                } else {
                    printf("Error: Division by zero not allowed\n");
                }
                break;
            default:
                printf("Invalid choice:select between 1 and 5\n");
        }
    }
    return 0;
}
double add(double a, double b) {
    return a + b;
}
double subtract(double a, double b) {
    return a - b;
}
double multiply(double a, double b) {
    return a * b;
}
double divide(double a, double b) {
    return a / b;
}