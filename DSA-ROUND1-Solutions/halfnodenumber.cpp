#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int val;
    node* left;
    node* right;

    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* root, int x)
{
    if(root == NULL)
    {
        return new node(x);
    }

    if(x < root->val)
    {
        root->left = insert(root->left, x);
    }
    else
    {
        root->right = insert(root->right, x);
    }

    return root;
}

int halfnodes(node* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int count = 0;
    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        bool hasLeft = temp->left != NULL;
        bool hasRight = temp->right != NULL;

        if((hasLeft && !hasRight) || (!hasLeft && hasRight))
        {
            count++;
        }

        if(temp->left)
        {
            q.push(temp->left);
        }

        if(temp->right)
        {
            q.push(temp->right);
        }
    }

    return count;
}

int main()
{
    node* root = NULL;
    int n, val;

    cout<<"how many numbers? ";
    cin>>n;

    cout<<"enter "<<n<<" values:\n";
    for(int i=0; i<n; i++)
    {
        cin>>val;
        root = insert(root, val);
    }

    int half = halfnodes(root);

    cout<<"\nnumber of half nodes: "<<half<<endl;

    return 0;
}