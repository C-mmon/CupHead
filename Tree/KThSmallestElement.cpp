class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* result = nullptr;
        inorder(root, k, result);
        return result->val;
    }

private:
    void inorder(TreeNode* node, int& k, TreeNode*& result) {
        if (!node || result) return;

        inorder(node->left, k, result);

        k--;
        if (k == 0) {
            result = node;
            return;
        }

        inorder(node->right, k, result);
    }
};
