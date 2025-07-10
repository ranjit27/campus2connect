#include <stdlib.h>
#include <stack>
#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
};

void reverseLL(struct Node *head){

    struct Node * temp = head;
    struct Node * prev = NULL;
    stack <int> st;

    while(temp -> next != NULL){
        temp = temp -> next;
        st.push(temp -> data);
    }

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    
}

int main(){
    struct Node * head = NULL;

    reverseLL(head);

    return 0;
}