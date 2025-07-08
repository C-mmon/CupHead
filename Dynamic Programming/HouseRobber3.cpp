/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0}; // Base case: {max_if_robbed, max_if_not_robbed}

        // Postorder traversal: calculate for left and right children first
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);

        // If we rob this node
        int rob = node->val + left.second + right.second;

        // If we don't rob this node
        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, not_rob};
    }

    int rob(TreeNode* root) {
        pair<int, int> result = dfs(root);
        return max(result.first, result.second); // Return the maximum of robbing or not robbing the root
    }
};
