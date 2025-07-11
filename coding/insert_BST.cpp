#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key) {
    if (root == NULL)
     return new Node(key);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new Node(key);
            return root;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new Node(key);
            return root;
        } else {
            q.push(temp->right);
        }
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(11);
    root->right = new Node(9);
    root->left->left = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "Inorder before: ";
    inorder(root);
    cout << endl;

    int key;
    cin >> key;

    root = insert(root, key);

    cout << "Inorder after: ";
    inorder(root);
    cout << endl;

    return 0;
}
