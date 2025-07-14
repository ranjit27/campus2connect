#include<iostream>
using namespace std;
struct Node{
  
    int data;
    Node *next=nullptr;
};


struct Node *head=NULL;

 void insert_node(int data)
{
    struct Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}


void print_ll(Node *head)
{
    if(head==NULL) return;
   print_ll(head->next);
   cout<<head->data<<" ";
}

int main(){

   insert_node(55);
   insert_node(100);
   insert_node(5);

   print_ll(head);
   cout<<"\nfinished";
   return 0;
}
