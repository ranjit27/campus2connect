#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sizeOfTree(TreeNode* root) {
    if (root == nullptr)
        return 0;

    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Size of Binary Tree: " << sizeOfTree(root) << endl;
    return 0;
}
