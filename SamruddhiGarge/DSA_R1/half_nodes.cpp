/*
Create a custom queue using an array to store nodes for level-order traversal.

Insert the root node into the queue.

While the queue is not empty, repeat:

Dequeue the front node.

If the node has exactly one child (either left or right but not both), increment the halfNodeCount.

Enqueue the left child (if it exists).

Enqueue the right child (if it exists).

After the traversal is complete, return halfNodeCount.


*/


#include <iostream>
using namespace std;


struct Node 
{
    int data;
      Node* left;
         Node* right;
};


Node* createNode(int val) 
{
    Node* newNode = new Node;
        newNode->data = val;
           newNode->left = newNode->right = NULL;
                return newNode;
}


struct Queue 
{
    Node* data[100];
       int front, rear;

    Queue() 
    {
        front = rear = -1;
    }

    bool isEmpty() 
    {
        return (front == -1 || front > rear);
    }

    void enqueue(Node* node)
     {
        if (rear < 99) 
        {
            if (front == -1) front = 0;
            data[++rear] = node;
        }
    }

    Node* dequeue() 
    {
        if (!isEmpty())
            return data[front++];
        return NULL;
    }
};


int countHalfNodes(Node* root)
 {
    if (root == NULL)
        return 0;

    Queue q;
    q.enqueue(root);
    int count = 0;

    while (!q.isEmpty()) 
    {
        Node* current = q.dequeue();

        bool hasLeft = current->left != NULL;
        bool hasRight = current->right != NULL;

        if ((hasLeft && !hasRight) || (!hasLeft && hasRight)) 
        {
            count++;
        }

        if (hasLeft) q.enqueue(current->left);
        if (hasRight) q.enqueue(current->right);
    }

    return count;
}


int main()
 {
    Node* root = createNode(1);
       root->left = createNode(2);
        root->right = createNode(3);
          root->left->right = createNode(4);
              root->left->right->left = createNode(5);

  
    int result = countHalfNodes(root);
        cout << "Number of half nodes: " << result << endl;

    return 0;
}
