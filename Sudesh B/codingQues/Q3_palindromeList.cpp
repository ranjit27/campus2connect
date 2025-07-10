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

bool isPalindrome(Node* head) {
    stack<int> s;
    Node* temp = head;

    // Push all elements into stack
    while (temp != nullptr) {
        s.push(temp->data);
        temp = temp->next;
    }

    // Compare again from head
    temp = head;
    while (temp != nullptr) {
        if (s.top() != temp->data)
            return false;
        s.pop();
        temp = temp->next;
    }

    return true;
}




int main(){
    Node * head = nullptr;

    insert(&head , 10);
    insert(&head , 20);
    insert(&head, 30);
    insert(&head , 20);
    insert(&head, 10);

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data<<" - ";
        temp = temp->next;
    }

    cout<<"\n";

    if(isPalindrome(head)){
        cout<<"The list is palindrome";
    }else{
        cout<<"The list is not palindrome";
    }
    

    return 0;
}
