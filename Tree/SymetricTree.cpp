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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return NULL;
        }
        return helper(root->left, root->right);
    }
    bool  helper(TreeNode* l1, TreeNode* r1)
    {
        //we have reached leaf node
        if(l1 ==  NULL && r1 == NULL)
        {
            return true;
        }
        //incase if they are not a leaf node 
        if(l1 == NULL || r1 == NULL)
        {
            return false;
        }
        //then check their value if they have the same value or not.

        if(l1->val != r1->val)
        {
            return false;
        }
        return helper(l1->left, r1->right) && helper(l1->right, r1->left);
    }
};
