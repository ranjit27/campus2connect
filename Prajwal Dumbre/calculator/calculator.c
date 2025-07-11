#include <stdio.h>

void calculate(float n1 , float n2, char ch) {

    float ans;

    switch (ch) {
        case '+':
            ans = n1 + n2;
            printf("%.2f + %.2f = %.2f\n", n1, n2, ans);
            break;
        case '-':
            ans = n1 - n2;
            printf("%.2f - %.2f = %.2f\n", n1, n2, ans);
            break;
        case '*':
            ans = n1 * n2;
            printf("%.2f * %.2f = %.2f\n", n1, n2, ans);
            break;
        case '/':
            if (n2 == 0) {
                printf("Error: Division by zero is not allowed!\n");
            } else {
                ans = n1 / n2;
                printf("%.2f / %.2f = %.2f\n", n1, n2, ans);
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

    float n1, n2, ans;

    printf("Welcome to the Calculator Program!\n");

    do {

        printf("Enter first number: ");
        if (scanf("%f", &n1) != 1) {
            printf("Invalid input.\n");
            while(getchar() != '\n');
            return -1;
        }

        printf("Enter second number: ");
        if (scanf("%f", &n2) != 1) {
            printf("Invalid input.\n");
            while(getchar() != '\n');
            return -1;
        }

        printf("Enter operation (+, -, *, /): ");
        scanf(" %c", &ch);

        calculate_pointer(n1, n2, ch);

        printf("Would you like to continue? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}