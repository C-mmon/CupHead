#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

// Collects and deletes leaf nodes in one traversal
TreeNode* removeLeaves(TreeNode* node, vector<int>& leaves) {
    if (!node) return nullptr;

    if (!node->left && !node->right) {
        leaves.push_back(node->val);
        delete node;
        return nullptr;
    }

    node->left = removeLeaves(node->left, leaves);
    node->right = removeLeaves(node->right, leaves);

    return node;
}

void printLeavesByLevel(TreeNode* root) {
    while (root->left || root->right) {
        vector<int> leaves;
        root = removeLeaves(root, leaves);
        for (int v : leaves) cout << v << " ";
        cout << endl;
    }

    // Finally print the root node
    cout << root->val << endl;
    delete root;
}

int main() {
    /*
              1
             / \
            2   3
           / \     
          4   5    
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    printLeavesByLevel(root);

    return 0;
}
