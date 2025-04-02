struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* findCenterNode(TreeNode* root) {
    if (!root) return nullptr;
    
    // Build adjacency list and degree map
    unordered_map<TreeNode*, vector<TreeNode*>> adj;
    unordered_map<TreeNode*, int> degree;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        auto node = q.front(); q.pop();
        if (node->left) {
            adj[node].push_back(node->left);
            adj[node->left].push_back(node);
            degree[node]++;
            degree[node->left]++;
            q.push(node->left);
        }
        if (node->right) {
            adj[node].push_back(node->right);
            adj[node->right].push_back(node);
            degree[node]++;
            degree[node->right]++;
            q.push(node->right);
        }
    }

    // Initialize leaves queue
    queue<TreeNode*> leaves;
    for (auto& [node, cnt] : degree) 
        if (cnt == 1) leaves.push(node);

    // Topological sort to find center
    int remaining = degree.size();
    while (remaining > 2) {
        int size = leaves.size();
        remaining -= size;
        for (int i = 0; i < size; ++i) {
            auto leaf = leaves.front(); leaves.pop();
            for (auto neighbor : adj[leaf]) {
                if (--degree[neighbor] == 1) 
                    leaves.push(neighbor);
            }
        }
    }
    
    // Return remaining node(s)
    return leaves.size() == 1 ? leaves.front() : leaves.back();
}
