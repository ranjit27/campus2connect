#include<iostream>
using namespace std;
struct Node{int data;Node*next;Node(int x){data=x;next=NULL;}};

void printReverse(Node*head){

if(!head)return;

printReverse(head->next);

cout<<head->data<<" ";

}

int main(){

Node*head=new Node(1);

head->next=new Node(2);

head->next->next=new Node(3);

head->next->next->next=new Node(4);

printReverse(head);

return 0;

}
