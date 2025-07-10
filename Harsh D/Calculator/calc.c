#include <stdio.h>

void calculate(float num1 , float num2, char ch) {

    float ans;

    switch (ch) {
        case '+':
            ans = num1 + num2;
            printf("%.2f + %.2f = %.2f\n", num1, num2, ans);
            break;
        case '-':
            ans = num1 - num2;
            printf("%.2f - %.2f = %.2f\n", num1, num2, ans);
            break;
        case '*':
            ans = num1 * num2;
            printf("%.2f * %.2f = %.2f\n", num1, num2, ans);
            break;
        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed!\n");
            } else {
                ans = num1 / num2;
                printf("%.2f / %.2f = %.2f\n", num1, num2, ans);
            }
            break;
        default:
            printf("Invalid operation! Please enter one of valid operator\n");
            break;
    }

    return;
}

int main() {
    char ch;

    void (*calculate_pointer)(float , float, char);
    calculate_pointer = calculate;

    float num1, num2, ans;

    printf("Welcome to the Calculator Program!\n");

    do {

        printf("Enter first number: ");
        if (scanf("%f", &num1) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            return -1;
        }

        printf("Enter second number: ");
        if (scanf("%f", &num2) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            return -1;
        }

        printf("Enter operation (+, -, *, /): ");
        scanf(" %c", &ch);

        calculate_pointer(num1, num2, ch);

        printf("Would you like to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    printf("Thank you for using my application\n");

    return 0;
}