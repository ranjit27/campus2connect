#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int countHalfNodes(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();

        // Check if it's a half node
        if ((curr->left && !curr->right) || (!curr->left && curr->right))
            count++;

        // Push children into the queue
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    return count;
}

int main() {


    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);  
    root->right->left = new Node(5);  
   

    cout << "Number of half nodes: " << countHalfNodes(root) << endl;

    return 0;
}