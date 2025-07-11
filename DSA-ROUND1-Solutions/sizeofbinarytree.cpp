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

int getsize(box* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + getsize(root->left) + getsize(root->right);
}

int main()
{
    box* root = NULL;
    int ch, num;

    do
    {
        cout<<"\n1. insert\n2. show inorder\n3. size\n4. exit\n";
        cout<<"enter choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"enter number to insert: ";
                cin>>num;
                root = insert(root, num);
                break;

            case 2:
                cout<<"inorder: ";
                inorder(root);
                cout<<endl;
                break;

            case 3:
                cout<<"size of bst: "<<getsize(root)<<endl;
                break;

            case 4:
                cout<<"exiting...\n";
                break;

            default:
                cout<<"invalid choice\n";
        }

    }while(ch != 4);

    return 0;
}