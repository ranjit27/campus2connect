#include<stdio.h>
#include<stack>
#include<cstdlib>
#include<iostream>

using namespace std; 

struct Node{
    int data;
    struct Node *next ;
};


Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insert(Node ** ref , int data){
    Node * newNode = CreateNode(data);

    if(*ref == NULL){
            *ref = newNode;
    }else{
        Node *temp = *ref;
        while(temp-> next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        
    }
}

void reverseList(Node * head){
    stack<int> st;

    while(head != nullptr){
        st.push(head->data);
        head = head->next;
    }

    while(!st.empty()){
        cout << st.top() << " <- ";
        st.pop();
    }
}


int main(){
    Node * head = nullptr;

    insert(&head , 10);
    insert(&head , 20);
    insert(&head, 30);
    insert(&head , 40);
    insert(&head, 50);

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data<<" -> ";
        temp = temp->next;
    }

    cout<<"\n";

    reverseList(head);

    return 0;
}
