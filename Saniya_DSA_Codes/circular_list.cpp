#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>res1;
vector<int>res2;

struct Node {
    int data;
    Node *next;

    Node (int val )
    {
        data=val;
        next = nullptr;
    }
};

void split(Node *head)
{
    Node *curr=head;
    curr=curr->next;
    int count=1;
    while( curr!=head)
    {
        curr=curr->next;
        count++;      
    }

    cout<<"count is : "<<count<<endl;

    
    
    if( count%2==0 )
    {
        int div=count/2;
        Node* temp=head;
        res1.push_back(head->data);
        temp=temp->next;
        int val=1;
        while( temp!=head)
        {
            if( val<div)
            {
                res1.push_back(temp->data);
            }
            else{
                res2.push_back(temp->data);
            }
            temp=temp->next;
            val++;
        }

    }
    else
    {
        int div=(count/2)+1;
        Node* temp=head;
        res1.push_back(head->data);
        temp=temp->next;
        int val=1;
        while( temp!=head)
        {
            if( val<div)
            {
                res1.push_back(temp->data);
            }
            else{
                res2.push_back(temp->data);
            }
            temp=temp->next;
            val++;
        }
    }
}

void printList(Node *head)
{
    Node *curr=head;
    cout<<curr->data<<" ";
    curr=curr->next;
    while( curr!=head)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
        
    }
    cout<<endl;
}

int main()
{
    Node *first=new Node(10);
    Node *second=new Node(20);
    Node *third=new Node(30);
    Node *fourth=new Node(40);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=first;

    printList(first);
    split(first);

    
    cout<<"First res"<<endl;
    for(int i=0;i<res1.size();i++)
    {
        cout<<res1[i]<<" ";
    }
    cout<<"Second res"<<endl;
    for(int i=0;i<res2.size();i++)
    {
        cout<<res2[i]<<" ";
    }

}