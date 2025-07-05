#include <stdio.h>

int main() {
    float num1, num2, result;
    char operation;
    char choice;

    printf("Welcome to the Calculator Program!\n"); 

    do {
        // Get first number
        printf("Enter first number: ");
        scanf("%f", &num1);

        // Get second number
        printf("Enter second number: ");
        scanf("%f", &num2);

        // Get operation
        printf("Enter operation (+, -, *, /): ");
        scanf(" %c", &operation); // space before %c is important to catch newline

        // Perform calculation
        switch (operation) {
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
                printf("Invalid operation! Please enter one of +, -, *, /\n");
        }

        // Ask user if they want to continue
        printf("Would you like to calculate again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Calculator Program.!\n");
    return 0;
}