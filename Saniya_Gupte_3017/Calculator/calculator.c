#include <stdio.h>


int main() {

    double num1, num2;
    char op;
    char choice;

    do{
        printf("Enter first number : ");
        scanf("%lf" , &num1);
        printf("Enter second number : ");
        scanf("%lf" , &num2);

        printf("Enter operation to be performed (+, -, *, /):");
        scanf(" %c" , &op);

        switch(op)
        {
            case '+':
            printf("Result : %.2lf\n" , num1+num2);
            break;

            case '-':
            printf("Result : %.2lf\n" , num1-num2);
            break;

            case '*':
            printf("Result : %.2lf\n" , num1*num2);
            break;

            case '/':
            if( num2==0 ){
                printf("Error : cannot perform division\n");
            }
            else{
                printf("Result : %.2lf\n" , num1/num2);
            }           
            break;

            default:
                printf("Invalid operator!\n");

        }

        printf("Do you want to perform another calculation? ( y/n) : ");
        scanf(" %c" , &choice);
    }
    while(choice== 'y');
    
    return 0;
}
