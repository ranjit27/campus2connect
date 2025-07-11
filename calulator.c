#include<stdio.h>
#include<stdlib.h>
int main()
{
    
    int add(int a, int b)
    {
        return a+b;
    }
    int sub(int a, int b)
    {
        return a-b;
    }
    int mul(int a, int b)
    {
        return a*b;
    }
    int div(int a, int b)
    {
        if(b==0)
        {
            printf("Denomitoe should not be zero");
            return 0;
        }
        return a/b;
    }

   
    int a,b,sum=0;
    printf("Enter two numbers\n");
    scanf("%d %d", &a, &b);
    int ch=0;
    printf("enter choice\n1. add\n2. sub\n3. mul\n4. div\n");
    scanf("%d", &ch);
    switch(ch)
    {
      case 1:
       { 
            sum = add(a, b);
            printf("Sum is %d\n", sum);
            break;
        }
        case 2:
            {
                sum = sub(a, b);
                printf("Sub is %d\n", sum);
                break;
            }
        case 3:
            {
                sum = mul(a, b);
                printf("Mul is %d\n", sum);
                break;
            }
        case 4:
            {
                sum = div(a, b);
                printf("Div is %d\n", sum);
                break;
            }
        default:{
            printf("Invalid choice\n");
        }
    }





     return 0;
}