#include <stdio.h>

int main() {
    float num1, num2, result;
    char op;
    char choice;

    printf("Welcome to the Calculator Program!\n");

    do {
        
        printf("\nEnter first number: ");
        scanf("%f", &num1);

        printf("Enter second number: ");
        scanf("%f", &num2);

        printf("Enter operation (+, -, *, /): ");
        scanf(" %c", &op);  // Notice the space before %c to ignore any leftover newline

        // Perform calculation
        switch (op) {
            case '+':
                result = num1 + num2;
                printf("%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed!\n");
                } else {
                    result = num1 / num2;
                    printf("%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            default:
                printf("Error: Invalid operation! Please use +, -, *, or /.\n");
        }

        // Ask user if they want to repeat
        printf("Would you like to calculate again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Calculator Program. Goodbye!\n");
    return 0;
}