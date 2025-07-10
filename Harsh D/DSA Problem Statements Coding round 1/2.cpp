#include <stdlib.h>
#include <stack>
#include <iostream>
#include <forward_list>

using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void splitCircularList(Node* head, Node** head1_ref, Node** head2_ref) {

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast->next->next == head) {
        fast = fast->next;
    }

    *head1_ref = head;
    *head2_ref = slow->next;

    slow->next = *head1_ref;
    fast->next = *head2_ref;
}

int main(){
    struct Node * head = NULL;
    struct Node * head1 = NULL;
    struct Node * head2 = NULL;

    //Point head to actual LL and send as argument

    splitCircularList(head ,&head1 , &head2);

    return 0;
}