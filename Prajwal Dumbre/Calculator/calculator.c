#include <stdio.h>

int main()
{
    float num1, num2, result;
    char op;
    int choice;

    do
    {

        if (choice == 1)        
        {
            printf("---------------------------------\n\n");
            printf("Enter first number: ");
            scanf("%f", &num1);

            printf("Enter second number: ");
            scanf("%f", &num2);

            printf("Select operation (+, -, *, /): ");
            scanf(" %c", &op);

            switch (op)
            {
            case '+':
                result = num1 + num2;
                printf("Result: %.2f\n\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %.2f\n\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("Result: %.2f\n\n", result);
                break;
            case '/':
                if (num2 == 0)
                {
                    printf("Error: Division by zero is not allowed.\n");
                }
                else
                {
                    result = num1 / num2;
                    printf("Result: %.2f\n\n", result);
                }
                break;
            default:
                printf("Invalid operation.\n");
            }
        }
        else if(choice == 2){
            num1 = result;
            printf("Enter number: ");
            scanf("%f", &num2);

            printf("Select operation (+, -, *, /): ");
            scanf(" %c", &op);
            switch (op)
            {
            case '+':
                result = num1 + num2;
                printf("Result: %.2f\n\n", result);
                break;
            case '-':
                result = num1 - num2;
                printf("Result: %.2f\n\n", result);
                break;
            case '*':
                result = num1 * num2;
                printf("Result: %.2f\n\n", result);
                break;
            case '/':
                if (num2 == 0)
                {
                    printf("Error: Division by zero is not\n\n allowed.");
                }
                else
                {
                    result = num1 / num2;
                    printf("Result: %.2f\n\n", result);
                }
                break;
            default:
                printf("Invalid operation.\n\n");
            }
        }

        printf("SELECT OPTION : \n 1. NEW CALCULATION  \n 2. CONTINUE CALCULATIONS \n\n");
        scanf(" %d", &choice);

    } while (choice == 1 || choice == 2);

    printf("Calculator closed.\n");
    return 0;
}
