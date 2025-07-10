//
// Created by Anish Sapre on 10/07/25.
//
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

void insert(Node*& root, int data) {
    if (root == nullptr) {
        root = new Node(data);
        return;
    }

    Node* temp = root;

    while (temp != nullptr) {
        if (data < temp->data) {
            if (temp->left == nullptr) {
                temp->left = new Node(data);
                return;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = new Node(data);
                return;
            } else {
                temp = temp->right;
            }
        }
    }
}

int size(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return size(root->left) + size(root->right) + 1;
}

void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int countHalfNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        bool hasLeft = (current->left != nullptr);
        bool hasRight = (current->right != nullptr);

        if ((hasLeft && !hasRight) || (!hasLeft && hasRight)) {
            count++;
        }
        if (hasLeft) {
            q.push(current->left);
        }
        if (hasRight) {
            q.push(current->right);
        }
    }
    return count;
}

int main() {
    Node* root = nullptr;
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 20);
    insert(root, 25);

    cout << "Inorder: ";
    inorderTraversal(root);
    cout << "\n";
    cout << "Half nodes: " << countHalfNodes(root) << endl;

    return 0;
}
