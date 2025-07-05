#include <stdio.h>


float add(float a, float b) {
    return a + b;
}

float sub(float a, float b) {
    return a - b;
}

float mul(float a, float b) {
    return a * b;
}

float divide(float a, float b) {
    return a / b;
}

int main() {
    float a, b;
    char operation, choice;

    start:
    printf("Enter 1st number: ");
    scanf("%f", &a);
    float result = a;

    do {
        printf("Enter operation: ");
        scanf(" %c", &operation);

        printf("Enter 2nd number: ");
        scanf("%f", &b);

        switch (operation) {
            case '+':
                result = add(result, b);
                break;
            case '-':
                result = sub(result, b);
                break;
            case '*':
                result = mul(result, b);
                break;
            case '/':
                if (b == 0) {
                    printf("ERROR\n");
                    continue;
                } else {
                    result = divide(result, b);
                }
                break;
            default:
                printf("INVALID OP\n");
                continue;
        }

        printf("Current result: %.2f\n", result);
        printf("What do? 1. Continue <<<<OR>>>> 2. Start new operations?: ");
        scanf(" %c", &choice);
        if (choice == '2') {
            goto start;
        }

    } while (choice == '1');

    printf("FINAL ANS: %f", result);
    return 0;
}
