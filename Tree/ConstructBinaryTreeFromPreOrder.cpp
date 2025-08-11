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
TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE)
{
    if(preS> preE || inS> inE)
    {
        return NULL;
    }
    TreeNode* root= new TreeNode(preorder[preS]);
    int i=inS;
    for(; i<=inE; i++)
    {
        if(preorder[preS] == inorder[i])
        {
            break;
        }
    }
    //these are indexes,we need elements
    int leftElement = i-inS; 
    int rightElement = inE-leftElement;
    root->left = helper(preorder, inorder, preS+1, preS+leftElement, inS, i-1);
    root->right = helper(preorder, inorder, preS+leftElement+1, preE, i+1,inE);
    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
