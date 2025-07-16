struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* leftMostNode(TreeNode* r) {
    while (r && r->left) {
        r = r->left;
    }
    return r;
}

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* parent, int inorder) {
    if (root == NULL) {
        return NULL;
    }

    if (root->val == inorder) {
        if (root->right) {
            return leftMostNode(root->right);
        } else {
            return parent;  // This may be NULL if it's the rightmost node
        }
    }

    if (inorder < root->val) {
        // Potential successor is current root
        return inorderSuccessor(root->left, root, inorder);
    } else {
        // Continue searching right, current root cannot be successor
        return inorderSuccessor(root->right, parent, inorder);
    }
}
