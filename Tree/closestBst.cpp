//find the closest value to the target in a bst tree
//efficient way to traverse dfs
//absolute difference concept
// Recursive DFS function
void dfs(TreeNode* node, double target, int& closest) {
    if (!node) return;

    // Update closest value if the current node is closer
    if (abs(node->val - target) < abs(closest - target)) {
        closest = node->val;
    }

    // DFS traversal: move left if target is smaller, move right otherwise
    if (target < node->val) {
        dfs(node->left, target, closest);
    } else {
        dfs(node->right, target, closest);
    }
}
