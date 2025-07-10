#include<stdlib.h>
#include <iostream>
#include <queue>

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

int findHalfNodes(Node * root){
    if(root == NULL){
        return 0;
    }

    queue<Node * > q;
    q.push(root);

    int cnt = 0;

    while(!q.empty()){
        Node * temp = q.front();
        q.pop();

        if ((temp->left == NULL) != (temp->right == NULL)) {
            cnt++;
        }

        if(temp -> left != NULL){
            q.push(temp -> left);
        }

        if(temp -> right != NULL){
            q.push(temp -> right);
        }
    }
}

int main(){
    Node * root = NULL;
    // initialize a bst here and send root

    int ret = findHalfNodes(root);

    cout<<ret<<endl;
}