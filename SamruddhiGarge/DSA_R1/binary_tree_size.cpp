/*
1. Prompt the user to enter the root node value.
2. If the value is -1, return NULL (tree is empty).
3. Create a root node with the given value.
4. Initialize a queue and enqueue the root node.

5. While the queue is not empty:
   a. Dequeue the front node from the queue.
   b. Ask the user for the left child of the current node.
      - If it's not -1, create the left child node and enqueue it.
   c. Ask the user for the right child of the current node.
      - If it's not -1, create the right child node and enqueue it.
*/
#include <iostream>
#include<conio.h>
#include <queue>
using namespace std;

// Structure for binary tree node
struct Node
 {
    int data;
    Node* left;
    Node* right;

    Node(int val)
     {
        data = val;
        left = right = NULL;
    }
};


Node* buildTree() 
{
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;

    if (val == -1) return NULL;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) 
    {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;
        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftVal;
        if (leftVal != -1)
         {
            current->left = new Node(leftVal);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightVal;
        if (rightVal != -1)
         {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }

    return root;
}


int sizeOfTree(Node* root)
 {
    if (root == NULL)
        return 0;
    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

int main()
 {
    Node* root = buildTree();
    int size = sizeOfTree(root);
    cout << "Size of the binary tree: " << size << endl;
    return 0;
}
