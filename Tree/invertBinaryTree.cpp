TreeNode* invertTree(TreeNode* root) {
    //to invert a binary tree.
    //swapping the nodes.
    if(root == nullptr)
    {
      return nullptr;
    }
    TreeNode* temp = root->left;
    root->left= root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;

//Note:To self remember swapping of the nodes