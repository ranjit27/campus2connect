#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    int choice;
    char cont = 'y';

    while (cont == 'y' || cont == 'Y') 
    {
          cout << "Enter first number: ";
          cin >> num1;
          cout << "Enter second number: ";
          cin >> num2;

        cout << "Select operation:\n";
        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        
        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Result: " << result << endl;
                break;

            case 2:
                if (num1 == num2){
                    result = num1 - num2 ;
                    cout << "result :" << result << endl;}
                else if(num1 > num2){
                    result = num1 - num2;
                    cout << "Result: " << result << endl;
                }
                else{
                    result = num2 - num1 ;
                    cout << "result :"<< result << endl ;
                }
                break;

            case 3:
                result = num1 * num2;
                cout << "Result: " << result << endl;
                break;

            case 4:
                if (num2 == 0)
                    cout << "Error: Division by zero" << endl;
                else {
                    result = num1 / num2;
                    cout << "Result: " << result << endl;
                }
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> cont;
    }

    cout << "Calculator exited" << endl;
    return 0;
}


/*#include <stdio.h>

double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2, result;
    int choice;
    char cont = 'y';
    double (*operation)(double, double);

    while (cont == 'y' || cont == 'Y') {
        printf("Enter first number: ");
        scanf("%lf", &num1);

        printf("Enter second number: ");
        scanf("%lf", &num2);

        printf("Select operation:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        if (choice == 1) operation = add;
        else if (choice == 2) operation = subtract;
        else if (choice == 3) operation = multiply;
        else if (choice == 4) operation = divide;
        else {
            printf("Invalid choice!\n");
            continue;
        }

        result = operation(num1, num2);
        printf("Result: %.2lf\n", result);

        printf("Do you want to perform another calculation? (y/n): ");
        scanf(" %c", &cont);
    }

    printf("Calculator exited.\n");
    return 0;
}

*/