#include<iostream>
#include<queue>
using namespace std;
struct Node{int data;Node*l;Node*r;Node(int x){data=x;l=r=NULL;}};

int halfNodes(Node*root){

if(!root)return 0;

queue<Node*>q;q.push(root);

int c=0;

while(!q.empty()){

Node*t=q.front();q.pop();

if((t->l&&!t->r)||(t->r&&!t->l))c++;

if(t->l)q.push(t->l);

if(t->r)q.push(t->r);

}

return c;

}

int main(){

Node*root=new Node(1);

root->l=new Node(2);

root->r=new Node(3);

root->l->l=new Node(4);

root->r->r=new Node(5);

root->r->r->l=new Node(6);

cout<<halfNodes(root)<<endl;

return 0;

}
