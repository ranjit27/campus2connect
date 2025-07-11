#include<stdio.h>


    float add(float a,float b){
        float c = a+ b ;
        return c ;
    }
    float sub(float a, float b){
        float c = a - b ;
        return c ;
    }
    float mul(float a, float b){
        float c = a * b ;
        return c ;
    }
    float div(float a, float b){
        if(b== 0 ){
             printf("Error: Division by zero!\n");
        return 0;
        }
       float c = a/b ;
       return c;
    }


int main()
{
    
    int choice ;
    float a, b , result;
    printf("enter a and b:\n");
    scanf("%f %f",&a, &b);
    printf("Enter your choice: \n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division \n 5. Exit \n") ;
    scanf("%d",&choice);
    while(choice!=5){
        
           switch(choice){
        case 1:
        result = add(a,b) ;
        printf("result = %f\n",result);
        break ;
        case 2:
        result =sub(a,b) ;
        printf("result = %f\n",result);
        break ;
        case 3:
        result = mul(a,b) ;
        printf("result = %f\n",result);
        break ;
        case 4:
        result = div(a,b) ;
        printf("result = %f\n",result);
        break ;

        default:
        printf("please enter correct choice:");

    }
    printf("Enter your choice: \n 1.Addition \n 2.Subtraction \n 3.Multiplication \n 4.Division \n 5. Exit \n") ;
     scanf("%d",&choice);
    }
  return 0 ;
}