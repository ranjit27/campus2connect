#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int findHalfNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if ((temp->left == nullptr) != (temp->right == nullptr)) {
            cnt++;
        }
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
    }
    return cnt;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->left->right = new Node(6);
    int ret = findHalfNodes(root);
    cout << "Number of half nodes: " << ret << endl;
    return 0;
}
