#include <stdio.h>

int main() 
{
    char operator;
    int n1, n2, result;
    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter two numbers: ");
    scanf( "%d %d",&n1, &n2);

    switch(operator) {
        case '+':
            result = n1 + n2;
            printf("Result: %d\n", result);
            break;
        case '-':
            result = n1 - n2;
            printf("Result: %d\n", result);
            break;
        case '*':
            result = n1 * n2;
            printf("Result: %d\n", result);
            break;
        case '/':
            if (n2 != 0)
                result = n1 / n2;
            else {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid operator.\n");
    }

return 0;
}