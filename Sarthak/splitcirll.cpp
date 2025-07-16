#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){data=x;next=NULL;}
};

void splitList(Node* head, Node** head1_ref, Node** head2_ref){
    Node *slow=head, *fast=head;

    if(head==NULL || head->next==head){
        *head1_ref=head;
        *head2_ref=NULL;
        return;
    }

    while(fast->next!=head && fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }

    if(fast->next->next==head) fast=fast->next;

    *head1_ref=head;
    *head2_ref=slow->next;

    fast->next=slow->next;
    slow->next=head;
}

void printList(Node* head){
    Node* temp=head;
    if(head!=NULL){
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
    }
    cout<<endl;
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=head; // circular

    Node *head1=NULL, *head2=NULL;

    splitList(head,&head1,&head2);

    cout<<"First half: ";
    printList(head1);

    cout<<"Second half: ";
    printList(head2);

    return 0;
}
