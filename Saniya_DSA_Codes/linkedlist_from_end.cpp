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

vector<int> reverseNode(Node *head)
{
    vector<int>res;
    Node *curr=head;
    while( curr!=NULL)
    {
        res.push_back(curr->data);
        curr=curr->next;
    }
    reverse(res.begin() , res.end());
    return res;
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

    vector<int>res= reverseNode(first);

    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }

}