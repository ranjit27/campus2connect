
#include <stdlib.h>
#include <stack>
#include <iostream>

using namespace std;

struct Node
{
    int val;
    struct Node *next;
};

Node *reverseLL(Node *head)
{

    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

bool isPalindrome(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {

        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newHead = reverseLL(slow->next);

    Node *first = head;
    Node *second = newHead;

    while (second != NULL)
    {

        if (first->val != second->val)
        {
            reverseLL(newHead);
            return false;
        }

        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}


int main(){

    struct Node  * head = NULL;

    //Initialize a linked list here and send head

    isPalindrome(head);
}