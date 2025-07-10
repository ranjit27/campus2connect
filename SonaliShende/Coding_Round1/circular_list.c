#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void create(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        temp->next = head;
    } else {
        struct Node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = temp;
        temp->next = head;
    }
}

void printList(struct Node* start) {
    if (start == NULL) return;
    struct Node* temp = start;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != start);
    printf("\n");
}

void splitList(struct Node* head, struct Node** head1, struct Node** head2) {
    struct Node *slow = head, *fast = head;

    if (head == NULL || head->next == head) {
        *head1 = head;
        *head2 = NULL;
        return;
    }

    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    if (fast->next->next == head)
        fast = fast->next;

    *head1 = head;
    *head2 = slow->next;

    slow->next = *head1;
    fast->next = *head2;
}

int main() {
    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d node values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        create(value);
    }

    printf("\nOriginal Circular Linked List:\n");
    printList(head);

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    splitList(head, &head1, &head2);

    printf("\nFirst half:\n");
    printList(head1);

    printf("Second half:\n");
    printList(head2);

    return 0;
}
