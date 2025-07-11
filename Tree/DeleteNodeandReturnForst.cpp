/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> ans;
    TreeNode* recurse(TreeNode* node, unordered_set<int>& st) {
        if (!node) {
            return nullptr;
        }
        node->left = recurse(node->left, st);
        node->right = recurse(node->right, st);
        if (st.find(node->val) != st.end()) {
            if (node->left) {
                ans.push_back(node->left);
            }
            if (node->right) {
                ans.push_back(node->right);
            }
            delete node;
            return nullptr;
        }
        return node;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());


        root = recurse(root, st);

        if (root) {
            ans.push_back(root);
        }

        return ans;
    }
};
