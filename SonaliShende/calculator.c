#include <stdio.h>

int main() {
    float num1, num2, result;
    char op, cont;
    do {
        printf("Enter the first number: ");
        if (scanf("%f", &num1) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &op);

        printf("Enter the second number: ");
        if (scanf("%f", &num2) != 1) {
            printf("Invalid input. Please enter a valid number.\n");
            while (getchar() != '\n');
            continue;
        }
        switch (op) {
            case '+': result = num1 + num2; break;
            case '-': result = num1 - num2; break;
            case '*': result = num1 * num2; break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                    continue;
                }
                result = num1 / num2;
                break;
            default:
                printf("Invalid operator. Please use +, -, *, or /.\n");
                continue;
        }

        printf("Result: %.2f %c %.2f = %.2f\n", num1, op, num2, result);

        printf("Do you want to calculate again? (y/n): ");
        scanf(" %c", &cont);

    } while (cont == 'y' || cont == 'Y');
    return 0;
}
