#include <unordered_set>
#include <vector>
#include <functional>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // This function finds the lowest common ancestor (LCA) of a list of nodes in a binary tree.
    TreeNode* lowestCommonAncestor(TreeNode* root, const std::vector<TreeNode*>& nodes) {
      
        // Create an unordered set to store the values of all target nodes for constant time checks.
        std::unordered_set<int> targetNodesValues;
        for (auto node : nodes) {
            targetNodesValues.insert(node->val);
        }
      
        // Define a depth-first search lambda function to find the LCA of the nodes.
        std::function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* currentNode) -> TreeNode* {
            // If we've reached a nullptr or one of the target nodes, return the current node.
            if (!currentNode || targetNodesValues.count(currentNode->val)) {
                return currentNode;
            }
          
            // Recur on the left and right subtrees.
            TreeNode* leftLCA = dfs(currentNode->left);
            TreeNode* rightLCA = dfs(currentNode->right);
          
            // If both sides return a non-nullptr, we've found the LCA.
            if (leftLCA && rightLCA) {
                return currentNode;
            }
          
            // Otherwise, if one side is nullptr, return the non-nullptr result.
            return leftLCA ? leftLCA : rightLCA;
        };
      
        // Begin the search from the root of the tree.
        return dfs(root);
    }
