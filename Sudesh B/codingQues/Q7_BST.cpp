#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

void insert(Node* root, int key) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = new Node(key);
            return;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = new Node(key);
            return;
        } else {
            q.push(temp->right);
        }
    }
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder before insertion: ";
    inorder(root);
    cout << endl;

    int key = 6;
    insert(root, key);

    cout << "Inorder after insertion: ";
    inorder(root);
    cout << endl;

    return 0;
}
