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

int sizeofbst(Node * root){

    if(root == NULL){
        return;
    }

    int leftside = sizeofbst(root -> left);
    int rightside = sizeofbst(root -> right);

    return leftside + rightside + 1;
}


void main(){
    Node * root = NULL;
    // initialize a bst here and send root

    int ret = sizeofbst(root);

    cout<<ret<<endl;
}