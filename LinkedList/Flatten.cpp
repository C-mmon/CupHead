The solution uses post-order recursion to:

Recursively flatten the left and right subtrees

If a left subtree exists:

Traverse to the rightmost node of the flattened left subtree

Connect this node's right pointer to the flattened right subtree

Move the entire left subtree to the right of the current node

Set the left child to nullptr (since we're forming a "right-only" chain)
  
class Solution {
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
    TreeNode* helper(TreeNode* root)
    {
        //base case 
        if(!root)
        {
            return NULL;
        }
        TreeNode* left= helper(root->left);
        TreeNode* right = helper(root->right);
        if(left)
        {
            TreeNode* trav = left;
            while(trav->right != NULL)
            {
                trav= trav->right;
            }
            trav->right = right;
            root->right = left; 
            root->left =  NULL;  
        }
        return root;
    }
};
