class Solution {
  public:
    vector<int> topView(Node *root) {
        if (!root) return {};
        
        map<int, int> topNode; // horizontal distance -> node value
        queue<pair<Node*, int>> q; // node, horizontal distance
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            
            // Only insert if it's the first node at that horizontal distance
            if (topNode.find(hd) == topNode.end()) {
                topNode[hd] = node->data;
            }
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        vector<int> result;
        for (auto [_, val] : topNode) {
            result.push_back(val);
        }
        return result;
    }
};
