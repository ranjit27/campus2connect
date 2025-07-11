#include <iostream>
using namespace std;

struct box
{
    int val;
    box* left;
    box* right;

    box(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

box* insert(box* root, int x)
{
    if(root == NULL)
    {
        return new box(x);
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

void inorder(box* root)
{
    if(root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    box* root = NULL;
    int n, num;

    cout << "how many values? ";
    cin >> n;

    cout << "enter " << n << " numbers:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        root = insert(root, num);
    }

    cout << "\ninorder traversal: ";
    inorder(root);

    return 0;
}