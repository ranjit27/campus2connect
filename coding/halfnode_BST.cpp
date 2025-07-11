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

int HalfNodes(Node* root) {
    if (root == NULL) return 0;

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        bool hasLeft = curr->left != NULL;
        bool hasRight = curr->right != NULL;

        if ((hasLeft && !hasRight) || (!hasLeft && hasRight)) {
            count++;
        }

        if (hasLeft) q.push(curr->left);
        if (hasRight) q.push(curr->right);
    }

    return count;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->right = new Node(6);

    cout << "Number of half nodes: " << HalfNodes(root) << endl;

    return 0;
}
