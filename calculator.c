/*
The calculator program will:
1. Prompt the user to enter two numbers.
2. Ask the user to select an operation (e.g., +, -, *, /).
3. Perform the requested calculation and display the result.
4. Handle basic error cases (e.g., division by zero).
5. Optionally, allow the user to perform multiple calculations in a loop.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num1, num2;
    int choice;
    int ans;
    printf("enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    do
    {
        printf("select operation to perform:\n");
        printf("1:Addition\n2:Subtraction\n3:Multiplication\n4:Division\n0:exit\n");
        printf("enter choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            ans = num1 + num2;
            printf("Answer of Addition:%d\n", ans);
            break;
        case 2:
            ans = num1 - num2;
            printf("Answer of subtraction:%d\n", ans);
            break;
        case 3:
            ans = num1 * num2;
            printf("Answer of Multiplication:%d\n", ans);
            break;
        case 4:
            if (num2 == 0)
            {
                printf("cannot divide by 0\n");
            }
            else
            {
                ans = num1 / num2;
            }

            printf("Answer of Division:%d\n", ans);
            break;

        case 0:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 0);

    return 0;
}
