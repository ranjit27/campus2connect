#include <stdio.h>

int main() {
    int n ,m ;

    printf("Enter two number :");
    scanf("%d %d",&n,&m);
    int choice;

 
   do
    {
    printf("Enter your choice\n");
    printf("1.Addition\n");
    printf("2.Subtraction\n");
    printf("3.Multiplication\n");
    printf("4.Division\n");
    printf("5.To exit\n");
    scanf("%d",&choice);
       
     switch (choice)
    {
    case 1:
        printf( "%d\n",n+m );
        break;

    case 2:
         printf( "%d\n",n-m );
        break;

     case 3:
         printf( "%d\n",n*m );
        break;

    case 4:
        if(m==0){
            printf("Error! Division by zero is not allowed.");
            break ;
        }
         printf( "%2f\n",(float)n/m );
        break; 

     case 5:
        printf("Exiting...\n");
         break;
    
    default:
        printf("Invalid choice");
        break;
    }
    
    } while (choice!=5);

    return 0;
}
