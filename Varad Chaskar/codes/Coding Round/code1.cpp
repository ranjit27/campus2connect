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

Node* reverseLinkLis(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node* newHead = reverseLinkLis(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

void printLinkLis(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout<< "Original Linked List:";
    printLinkLis(head);
    cout << endl;

    head = reverseLinkLis(head);

    cout<< "Reversed Linked List:";
    printLinkLis(head);
    cout<< endl;
    return 0;    
}


