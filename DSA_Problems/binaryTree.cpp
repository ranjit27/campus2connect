#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() : root(nullptr) {}
    void insert(int val) {
        TreeNode* newNode = new TreeNode(val);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left == nullptr) {
                node->left = newNode;
                return;
            } else {
                q.push(node->left);
            }

            if (node->right == nullptr) {
                node->right = newNode;
                return;
            } else {
                q.push(node->right);
            }
        }
    }
    vector<int> levelOrderTraversal() {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        return result;
    }
    void printLevelOrder() {
        vector<int> traversal = levelOrderTraversal();
        for (int val : traversal) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    cout << "Level Order Traversal: ";
    tree.printLevelOrder();

    return 0;
}
