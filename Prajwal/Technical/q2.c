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
        newNode->next = head;
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void display(struct Node* start) {
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = start;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("(%d)\n", start->data);
}

void split(struct Node* head, struct Node** head1, struct Node** head2) {
    if (head == NULL || head->next == head) {
        *head1 = head;
        *head2 = NULL;
        return;
    }

    struct Node* slow = head;
    struct Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;

    fast->next = *head2;
}

int main() {
    
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    printf("Original List:\n");
    display(head);

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    split(head, &head1, &head2);

    printf("\nFirst Half:\n");
    display(head1);

    printf("Second Half:\n");
    display(head2);

    return 0;
}