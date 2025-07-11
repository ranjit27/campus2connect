#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int isPalindrome(char str[])
{
    char stack[MAX];
    int top = -1;
    int i=0;

    while (str[i] != '\0' && str[i] != 'X')
    {
        stack[++top] = str[i];
        i++;
    }

    if (str[i] != 'X')
    {
        return 0;
    }

    i++;
    while(str[i] != '\0')
    {
        if(top<0 || str[i] != stack[top--])
        {
            return 0;
        }
        i++;
    }

    return top == -1;
}

int main() 
{
    char str1[] = "ababaXababa";
    char str2[] = "abaaXababa";
    char str3[] = "ababaabaa";

    if(isPalindrome(str3))
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not Palindrome");
    }
}