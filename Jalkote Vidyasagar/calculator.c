#include <stdio.h>

int main() {
    float num1, num2, result;
    int choice;
    char repeat;

    printf("Welcome to the Calculator Program!\n");

    do {
        // Input: First and second numbers
        printf("\nEnter first number: ");
        scanf("%f", &num1);

        printf("Enter second number: ");
        scanf("%f", &num2);

        // Operation Menu
        printf("\nChoose an operation:\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        // Perform operation
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("\n%.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("\n%.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("\n%.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                if (num2 == 0) {
                    printf("\nError: Division by zero is not allowed!\n");
                } else {
                    result = num1 / num2;
                    printf("\n%.2f / %.2f = %.2f\n", num1, num2, result);
                }
                break;
            default:
                printf("\nInvalid choice! Please enter 1 to 4.\n");
        }

        // Repeat?
        printf("\nWould you like to calculate again? (y/n): ");
        scanf(" %c", &repeat);  // Note the space before %c to catch newline

    } while (repeat == 'y' || repeat == 'Y');

    printf("\nThank you for using the Calculator Program. Goodbye!\n");

    return 0;
}

 