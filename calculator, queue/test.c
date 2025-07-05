#include <stdio.h>

int main() {
    double num1, num2, result;
    char op;
    char choice;

    do {
        printf("Please enter two numbers:\n");

        printf("First number  : ");
        scanf("%lf", &num1);

        printf("Second number : ");
        scanf("%lf", &num2);

        printf("\nChoose an operation from the menu:\n");
        printf("1.Addition\n");
        printf("2.Subtyraction\n");
        printf("3.Multiplication\n");
        printf(" 4.Division\n");
        printf("Enter your choice: ");
        scanf(" %c", &op);

        switch(op) {
            case '1':
                result = num1 + num2;
                printf("Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '2':
                result = num1 - num2;
                printf("Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '3':
                result = num1 * num2;
                printf("Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;
            case '4':
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is not allowed!\n");
                }
                break;
            default:
                printf("Invalid operator: %c\n", op);
        }

        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');


    return 0;
}
