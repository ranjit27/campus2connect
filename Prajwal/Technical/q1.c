#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d - ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void displayFromEnd(struct Node* node) {
    if (node == NULL)
        return;
    displayFromEnd(node->next);
    printf("%d - ", node->data);
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(30);

    display();

    printf("List from end: ");
    displayFromEnd(head);
    printf("NULL\n");

    return 0;
}