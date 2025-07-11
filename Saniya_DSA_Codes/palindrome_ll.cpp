#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node (int val )
    {
        data=val;
        next = nullptr;
    }
};

bool ispalindrome(Node *head)
{
    Node *temp=head;
    vector<int>res;

    while( temp!=NULL)
    {
        res.push_back(temp->data);
        temp=temp->next;
    }

    int left=0 , right=res.size()-1;
    while( left < right)
    {
        if( res[left]!=res[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

void printList(Node *head)
{
    Node *curr=head;
    while( curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

int main()
{
    Node *first=new Node(10);
    Node *second=new Node(20);
    Node *third=new Node(30);
    first->next=second;
    second->next=third;
    third->next=NULL;

    printList(first);

    if( !ispalindrome(first))
    {
        cout<<"False";
    }
    else{
        cout<<"True";
    }

}