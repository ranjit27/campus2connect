#include<stdio.h>

void calculation(int a, int b)
{
    int choice = 0;
    while (choice <= 5)
    {
        printf("\nSelect an operation:\n 1) + \n 2) - \n 3) * \n 4) / \n 5) Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Addition: %d\n", a + b);
                break;
            case 2:
                if (a > b)
                    printf("Subtraction: %d\n", a - b);
                else
                    printf("Subtraction: %d\n", b - a);
                break;
            case 3:
                printf("Multiplication: %d\n", a * b);
                break;
            case 4:
                if (a == 0 || b == 0)
                    printf("Cannot divide by zero\n");
                else
                    printf("Division: %d\n", a / b);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
}

void main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("You entered %d and %d\n", a, b);
    calculation(a, b);

    
}

