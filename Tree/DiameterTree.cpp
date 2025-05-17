//Diameter of the tree is the longest path between any two node in the tree.
//for each left and right part, we can calcualte the max Diameter.
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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0; // Initialize diameter
        height(root, diameter); // Calculate the height and update diameter
        return diameter; // Return the maximum diameter found
    }

private:
    int height(TreeNode* root, int &diameter) {
        if (root == NULL) {
            return 0; // Base case: height of an empty tree is 0
        }

        // Recursively calculate the heights of left and right subtrees
        int leftSubtreeHeight = height(root->left, diameter);
        int rightSubtreeHeight = height(root->right, diameter);

        // Calculate the diameter through the current node
        diameter = max(diameter, leftSubtreeHeight + rightSubtreeHeight);

        // Return the height of the current node
        return max(leftSubtreeHeight, rightSubtreeHeight) + 1;
    }
};
