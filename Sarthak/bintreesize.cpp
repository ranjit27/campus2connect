#include<iostream>
using namespace std;
struct Node{int data;Node*l;Node*r;Node(int x){data=x;l=r=NULL;}};

int size(Node*root){

if(!root)return 0;

return size(root->l)+size(root->r)+1;

}

int main(){

Node*root=new Node(1);

root->l=new Node(2);

root->r=new Node(3);

root->l->l=new Node(4);

root->l->r=new Node(5);

cout<<size(root)<<endl;

return 0;

}
