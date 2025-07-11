#include <iostream>
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

int getSize(Node* root) {
    if (root == NULL) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    cout << "Size of tree: " << getSize(root) << endl;

    return 0;
}
