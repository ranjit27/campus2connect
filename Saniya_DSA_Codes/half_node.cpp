#include<iostream>
#include<queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

int countHalfNodes(Node* root)
{
    if(root == NULL) return 0;

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if( (temp->left == NULL && temp->right != NULL) ||
            (temp->left != NULL && temp->right == NULL) )
        {
            count++;
        }

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }

    return count;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->right->right = new Node(50);

    int res = countHalfNodes(root);
    cout << "Number of half nodes: " << res << endl;
}
