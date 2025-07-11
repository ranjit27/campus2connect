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

int countHalfNodes(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        bool hasLeft = current->left != nullptr;
        bool hasRight = current->right != nullptr;

        if ((hasLeft && !hasRight) || (!hasLeft && hasRight))
            count++;

        if (hasLeft) q.push(current->left);
        if (hasRight) q.push(current->right);
    }

    return count;
}

// Main
int main() {
   
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);  

    cout << "Number of half nodes: " << countHalfNodes(root) << endl;

    return 0;
}
