#include<iostream>
using namespace std;
struct Node{int data;Node*next;};

int main(){

Node*head=NULL,*head1=NULL,*head2=NULL,*temp=NULL,*slow=NULL,*fast=NULL;

int arr[]={5,4,3,2,1};

for(int i=0;i<5;i++){

Node*n=new Node();
n->data=arr[i];

if(head==NULL){

head=n;
n->next=n;

}

else{

n->next=head->next;
head->next=n;

}

}



slow=head->next;
fast=head->next;

while(fast->next!=head->next&&fast->next->next!=head->next){

slow=slow->next;
fast=fast->next->next;

}

if(fast->next->next==head->next)

fast=fast->next;

head1=head->next;
head2=slow->next;

fast->next=slow->next;
slow->next=head1;

cout<<"First:";

temp=head1;
do{
cout<<temp->data<<" ";
temp=temp->next;
}while(temp!=head1);

cout<<endl<<"Second:";

temp=head2;
do{
cout<<temp->data<<" ";
temp=temp->next;
}while(temp!=head2);

return 0;

}
