#include<stdio.h>

int main(){
    float num1, num2, res; 
    char sign, choice;

    printf("Welcome to the Calculator Program...!");

    do {
        printf("\nEnter First Number: ");
        scanf("%f", &num1);

        printf("\nEnter Second Number: ");
        scanf("%f", &num2);

        printf("\nEnter the operation you want to perform (+, -, *, /, %%): ");
        scanf(" %c", &sign);  

        switch(sign){
            case '+':
                res = num1 + num2;
                printf("Addition is %.2f", res);
                break;
            case '-':
                res = num1 - num2;
                printf("Substraction %.2f", res);
                break;
            case '*':
                res = num1 * num2;
                printf("Multiplication is %.2f", res);
                break;
            case '/':
                if(num2 == 0)
                    printf("Error: Division by zero is not allowed!");
                else {
                    res = num1 / num2;
                    printf("Division is %.2f", res);
                }
                break;
            case '%':
                if ((int)num2 == 0)
                    printf("Error: Modulo by zero is not allowed!");
                else {
                    int r = (int)num1 % (int)num2;
                    printf("Remainder is %d", r);
                }
                break;
            default:
                printf("Invalid operation!");
        }

        printf("\nWould you like to calculate again? (y/n): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    return 0;
}

