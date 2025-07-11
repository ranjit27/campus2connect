#include<stdlib.h>
#include <iostream>


using namespace std;

struct Node
{
    int data;
    struct Node * left;
    struct Node * right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void insertNodeinBST(int data , struct Node * root){

    if(root == NULL){
        return;
    }

    struct Node * temp = root;

    while(temp != NULL){
        if(data < temp -> data){
            if(temp -> left == NULL){
                temp -> left = new Node(data);
                return;
            }else{
                temp = temp -> left;
            }
        }else{
            if(temp -> right == NULL){
                temp -> right = new Node(data);
                return;
            }else{
                temp = temp -> right;
            }
        }
    }

    return;
}

void main(){

    Node * root = NULL;
    // initialize a bst here and send root

    insertNodeinBST(5 , root);
}