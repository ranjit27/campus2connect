#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* temp = *headRef;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void printReverse(Node* head)
{
    int stack[MAX], top=-1;
    Node* temp = head;

    while (temp != NULL)
    {
        stack[++top] = temp->data;
        temp = temp->next;
    }

    while (top >= 0)
    {
        printf("%d -> ", stack[top--]);
    }
    printf("Null\n");
}


int main() 
{
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);

    printReverse(head);
    return 0;
}
