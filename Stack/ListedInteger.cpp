int dfs(Node* node, int depth) {
    if (node->isInteger) {
        return node->value * depth;
    }

    int sum = 0;
    for (Node* child : node->children) {
        sum += dfs(child, depth + 1);
    }
    return sum;
}

int getWeightSum(Node* root) {
    return dfs(root, 1);  // start with depth = 1
}
