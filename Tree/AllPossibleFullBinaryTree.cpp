/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> recurse(int n) {
        // the value of n should always be odd
        if (n % 2 == 0) {
            return {};
        }
        // what does n ==1 means, that means we can only form the root, no
        // further, left and right can exist
        if (n == 1) {
            TreeNode* r = new TreeNode(0);
            return {r}; // return a single node
        }
        vector<TreeNode*> result;
        if (memo.count(n)) {
            return memo[n];
        }
        // every thing is zero based indexing
        for (int i = 1; i < n; i += 2) {

            // each subtree must have odd number of odds, and then we keep
            // incrementing by 2,
            vector<TreeNode*> leftPossible = recurse(i);
            vector<TreeNode*> rightPossible = recurse(n - i - 1);

            for (auto &leftNode : leftPossible) {
                for (auto &rightNode : rightPossible) {
                    TreeNode* store = new TreeNode(0);
                    store->left = leftNode;
                    store->right = rightNode;
                    result.push_back(store);
                }
            }
        }
        return memo[n] = result;
    }
    vector<TreeNode*> allPossibleFBT(int n) { return recurse(n); }
};
