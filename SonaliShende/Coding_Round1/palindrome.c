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
    } else {
        struct Node* current = head;
        while (current->next != NULL)
            current = current->next;
        current->next = temp;
    }
}

struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int isPalindrome() {
    if (head == NULL || head->next == NULL)
        return 1;

    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* secondHalf = reverse(slow->next);

    struct Node* firstHalf = head;
    struct Node* tempSecond = secondHalf;

    int result = 1;
    while (tempSecond != NULL) {
        if (firstHalf->data != tempSecond->data) {
            result = 0;
            break;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }

    return result;
}

void printList(struct Node* start) {
    struct Node* temp = start;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
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

    printf("\nLinked List:\n");
    printList(head);

    if (isPalindrome())
        printf("The linked list is a palindrome.\n");
    else
        printf("The linked list is not a palindrome.\n");

    return 0;
}
