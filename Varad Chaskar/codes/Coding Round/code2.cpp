#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data1, Node* next1)
        {
            data = data1;
            next = next1;
        }

        Node(int data1)
        {
            data = data1;
            next = nullptr;
        }
};


void CircLLSplit(Node* head, Node** headf, Node** heads)
{
    if(head == nullptr)
    return;
    Node* slow = head; 
    Node* fast = head;
    while(fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast->next->next == head) {
        fast = fast->next;
    }

    *headf = head;
    *heads = slow->next;

    slow->next = head;
    fast->next = *heads;
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node(new_data);
    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
        return;
    }

    while (last->next != *head_ref) {
        last = last->next;
    }

    last->next = new_node;
    new_node->next = *head_ref;
}

void printLinkLis(Node* head)
{
    Node* temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
}

int main()
{
    Node* head = nullptr;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    push(&head,5);
    push(&head,6);


    cout << "Original Circular Linked List: ";
    printLinkLis(head);
    cout << endl;

    Node* headf = nullptr;
    Node* heads = nullptr;
    CircLLSplit(head, &headf, &heads);

    cout << "First Half: ";
    printLinkLis(headf);
    cout << endl;

    cout << "Second Half: ";
    printLinkLis(heads);
    cout << endl;

    return 0;    
}