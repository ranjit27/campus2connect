#include <iostream>
#include <stack>
using namespace std;


struct Node 
{
     int value;
     Node* next;

    Node(int val) 
    {
        value = val;
        next = nullptr;
    }
    
};


void addelement(Node*& head, int val) 
{
    Node* newNode = new Node(val);

       if (head == nullptr) 
          {
            head = newNode;
             return;
          }


    Node* current = head;
    
    while (current->next != nullptr) 
       {
          current = current->next;
       }

    current->next = newNode;
}



void reverselist(Node* head)
  {
    if (head == nullptr) 
    {
         cout << "list is empty" << endl;
          return;
    }

     stack<int> st;
     Node* temp = head;

    while (temp != nullptr)
      {
        st.push(temp->value);
        temp = temp->next;
      }

    cout << "Reversed Linked List = ";
    
    while (!st.empty()) 
     {
        cout << st.top() << " ";
        st.pop();
      }
    cout << endl;
}


int main() 
   {
       
     Node* head = nullptr;
     int n;
     int input;

     cout << "How many elements do you want to take ? ";
     cin >> n;

    cout << "Enter " << n << " elements:\n";
    
      for (int i = 0; i < n; ++i) 
      {
        cin >> input;
        addelement(head, input);
      }

    reverselist(head);

    return 0;
}