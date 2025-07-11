#include <iostream>
using namespace std;

class Node 
{
  public:
         int val;
         Node* next;

    Node(int data) 
      {
        val = data;
        next = NULL;
      }
};


void addnode(Node*& head, int data)
  {
    Node* newnode = new Node(data);

       if (head == NULL)
        {
          head = newnode;
          newnode->next = head;
          return;
        }

    Node* temp = head;
    
    while (temp->next != head)
        temp = temp->next;

    temp->next = newnode;
    newnode->next = head;
}


void display(Node* head) 
{
       if (head == NULL) 
       {
        cout << "Empty list.\n";
        return;
       }

    Node* temp = head;
    do
      {
        cout << temp->val << " ";
        temp = temp->next;
       } 
    while (temp != head);
    cout << endl;
}


void splitlist(Node* head, Node*& head1, Node*& head2) 
   {
    if (head == NULL || head->next == head) 
      {
        head1 = head;
        head2 = NULL;
        return;
      }

    Node* slow = head;
    Node* fast = head;

    while (fast->next != head && fast->next->next != head) 
      {
        slow = slow->next;
        fast = fast->next->next;
      }

    
      if (fast->next->next == head)
        fast = fast->next;

         head1 = head;
         head2 = slow->next;

        slow->next = head1;
        fast->next = head2;
    }


int main() 
  {
    Node* head = NULL;
    int n, x;

    cout << "How many nodes you want to enter ? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    
    for (int i = 0; i < n; i++) 
      {
        cin >> x;
        addnode(head, x);
      }

    Node *first = NULL, *second = NULL;
    splitlist(head, first, second);

    cout << "\nFirst Half: ";
    display(first);

    cout << "Second Half: ";
    display(second);

    return 0;
}