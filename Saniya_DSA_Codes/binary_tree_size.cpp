#include<iostream>

using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


int getsize(Node *root)
    {
        if( root==NULL ) return 0;
        
        int left=getsize(root->left);
        int right=getsize(root->right);
        
        return left+right+1;
        
    }
int getSize(Node* node) {
        // code here
        return getsize(node);
    }


int main()
{
    Node *root=new Node(20);
    Node *one=new Node(10);
    Node *two=new Node(30);
    root->left=one;
    root->right=two;
    int res=getSize(root);
    cout<<"size is:"<<res<<endl;

}