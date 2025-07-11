#include <stdio.h>

void main()
{
    double a, b, res;
    int q = 0;
    char c;
    printf("--------Calculator--------\n");
    scanf(" %lf", &a);
    res = a;
    while(1)
    {
        a = res;
        scanf(" %c", &c);
        scanf("%lf", &b);
        switch(c)
        {
            case 'q':
                printf("Exiting calculator.\n");
                return;
            case '+':
                res = a+b;
                printf("Result: %lf\n", res);
                break;
            case '-':
                res = a-b;
                printf("Result: %lf\n", res);
                break;
            case '*':
                res = a*b;
                printf("Result: %lf\n", res);
                break;
            case '/':
                if(b != 0)
                {
                    res = a / b;
                    printf("Result: %lf\n", res);
                }
                else
                    printf("Error: Division by zero\n");
                break;
            default:
                printf("Error: Invalid operator\n");
        }
    }

}