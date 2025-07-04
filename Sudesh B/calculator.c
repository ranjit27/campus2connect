
#include <stdio.h>

int main() {
    float num1, num2, result;
    char op;
    char choice;

    printf("===== Welcome to Simple C Calculator =====\n");

    do {
        // Input numbers
        printf("\nEnter first number: ");
        scanf("%f", &num1);

        printf("Enter second number: ");
        scanf("%f", &num2);

        // Input operation
        printf("Choose operation (+, -, *, /): ");
        scanf(" %c", &op);  // Note the space before %c to consume any leftover newline

        // Perform calculation
        switch (op) {
            case '+':
                result = num1 + num2;
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case '*':
                result = num1 * num2;
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed!\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            default:
                printf("Error: Invalid operation. Please choose +, -, *, or /.\n");
        }

        // Ask if user wants to continue
        printf("\nDo you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the calculator!\n");

    return 0;
}
