#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int countHalfNodes(TreeNode* root) {
    if (root == nullptr)
        return 0;

    queue<TreeNode*> q;
    q.push(root);
    int count = 0;

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        bool hasLeft = current->left != nullptr;
        bool hasRight = current->right != nullptr;

        if ((hasLeft && !hasRight) || (!hasLeft && hasRight)) {
            count++;
        }

        if (hasLeft) q.push(current->left);
        if (hasRight) q.push(current->right);
    }

    return count;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    int halfNodeCount = countHalfNodes(root);
    cout << "Number of half nodes: " << halfNodeCount << endl;  // Output: 2

    return 0;
}
