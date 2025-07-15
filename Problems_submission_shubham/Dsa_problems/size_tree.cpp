#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int size(Node* root) {
    if (root == nullptr)
        return 0;
    return size(root->left) + size(root->right) + 1;
}

int main() {
   
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Size of tree: " << size(root) << endl;

    return 0;
}