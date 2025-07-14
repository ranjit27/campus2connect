/* Algorithm:

1. **Create a new node**:

   * Allocate memory and set `data = value`, `left = NULL`, and `right = NULL`.

2. **If the tree is empty (root == NULL)**:

   * Assign the new node as the `root` of the tree.
   * Terminate the algorithm.

3. **Initialize a queue**:

   * Use a queue to perform level-order traversal (breadth-first search).
   * Enqueue the `root` node.

4. Traverse the tree level by level:

   aWhile the queue is **not empty**:

     1. **Dequeue the front node** and store it in `current`.
     2. **Check if the left child of `current` is NULL**:

        * If **yes**, insert the new node as the **left child**.
        * Terminate the algorithm.
     3. **Otherwise**, enqueue the **left child** of `current`.
     4. **Check if the right child of `current` is NULL**:

        * If **yes**, insert the new node as the **right child**.
        * Terminate the algorithm.
     5. **Otherwise**, enqueue the **right child** of `current`.*/



#include <iostream>
#include <queue>
using namespace std;


struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};

void insert(Node *&root, int value)
{
    Node *newNode = new Node(value);

    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp->left == nullptr)
        {
            temp->left = newNode;
            return;
        }
        else
        {
            q.push(temp->left);
        }

        if (temp->right == nullptr)
        {
            temp->right = newNode;
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}


void inorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    int n, val;

    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        insert(root, val);
    }

    cout << "Inorder traversal of binary tree: ";
    inorder(root);
    cout << endl;

    return 0;
}

