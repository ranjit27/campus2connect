#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

void insert(int value) {
    if (isEmpty()) {
        push(value);
    } else {
        int temp = pop();
        insert(value);
        push(temp);
    }
}

void reverseStack() {
    if (!isEmpty()) {
        int temp = pop();
        reverseStack();
        insert(temp);
    }
}

void display() {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    printf("Original Stack: ");
    display();

    reverseStack();

    printf("Reversed Stack: ");
    display();

    return 0;
}
