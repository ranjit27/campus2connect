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

int check(Node* head)
{
    int stack[MAX], top=-1;

    Node* temp = head;

    while(temp != NULL)
    {
        stack[++top] = temp->data;
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL)
    {
        if(temp->data != stack[top--])
        {
            return 0;
        }
        temp = temp->next;
    }

    return 1;

}

void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

int main() 
{
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 20);
    append(&head, 10);

    int res = check(head);
    if (res == 0)
    {
        printf("Not Palindrome");
    }
    else
    {
        printf("Palindrome");
    }
    return 0;
}