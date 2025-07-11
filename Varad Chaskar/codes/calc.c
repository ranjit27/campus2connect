#include <stdlib.h>
#include <stdio.h>

int main()
{
    int ch,n1,n2;
    printf("Enter the two numbers:\n");
    scanf("%d%d",&n1,&n2);

    while(1)
    {
        printf("\n1.Addition\n2.Substraction\n3.Multiplication\n4.Division\n5.Quit\nEnter Your Choice:\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
            printf("Addition Result: %d\n", n1+n2);
            break;
            
            case 2:
            printf("Subtraction Result: %d\n", n1-n2);
            break;

            case 3:
            printf("Multiplication Result: %d\n", n1*n2);
            break;

            case 4:
            if(n2 != 0)
            {
                printf("Division Result: %.2f\n", (double) n1/n2);
            }
            else {printf("Undefined\n");}
            break;


            case 5:
            exit(0);
            break;
            
            default:
            printf("invalid choide");
            break;
        }
    }
    return 0;
}