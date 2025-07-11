#include<stdio.h>
#include<stdbool.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;



void initialize(Stack *s)
{
    s->top = -1;
}

bool isEmpty(Stack *s)
{
    return s->top == -1;
}

bool isFull(Stack *s)
{
    return s->top == MAX - 1;
}

void push(Stack *s, int val)
{
    if(isFull(s))
    {
        printf("Stack full\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack empty\n");
        return -1;
    }
    return s->arr[s->top--];
}

void printStack(Stack *s)
{
    for (int i=s->top; i>=0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void reverseStack(Stack *s, Stack *s1)
{
    while(!isEmpty(s))
    {
        int val = pop(s);
        push(s1, val);
    }
}

int main()
{
    Stack s;
    Stack s1;

    initialize(&s);
    initialize(&s1);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    printf("Stack before: \n");
    printStack(&s);

    reverseStack(&s, &s1);

    printf("\n\nStack after: \n");
    printStack(&s1);
}