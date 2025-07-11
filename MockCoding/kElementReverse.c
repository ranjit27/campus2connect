#include <stdio.h>

#define MAX 100

void reverse(int queue[], int n, int k) 
{
    if (k > n || k < 0) 
    {
        return;
    }

    int stack[MAX];
    int top = -1;

    for (int i = 0; i < k; i++) 
    {
        stack[++top] = queue[i];
    }

    for (int i = 0; i < k; i++) 
    {
        queue[i] = stack[top--];
    }

    int temp[MAX];
    int idx = 0;

    for (int i = k; i < n; i++) 
    {
        temp[idx++] = queue[i];
    }

    for (int i = 0; i < idx; i++) 
    {
        queue[k + i] = temp[i];
    }
}

void printQueue(int queue[], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() 
{
    int queue[MAX] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n = 9;
    int k = 4;

    printf("\nBefore\n");
    printQueue(queue, n);

    reverse(queue, n, k);

    printf("\nAfter\n");
    printQueue(queue, n);

    return 0;
}
