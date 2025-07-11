#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void insert(Node* root, int key)
{
    if(root == NULL)
    {
        root = new Node(key);
        return;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left == NULL)
        {
            temp->left = new Node(key);
            return;
        }
        else
        {
            q.push(temp->left);
        }

        if(temp->right == NULL)
        {
            temp->right = new Node(key);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}

void printLevelOrder(Node* root)
{
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);

    insert(root, 50);

    printLevelOrder(root);
}
