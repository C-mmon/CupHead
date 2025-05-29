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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }

        queue<TreeNode*> st;
        vector<vector<int>> res;
        st.push(root);
        bool leftToRight = true;
        int idx;
        while (!st.empty()) {
            int qSize = st.size();
            vector<int> currLevel (qSize);
            for (int i = 0; i < qSize; i++) {
                TreeNode* front = st.front();
                st.pop();
                if(!leftToRight)
                {
                    idx= qSize-i-1;
                }
                else
                {

                    idx=i;
                }
                currLevel[idx]= front->val;
                if (front->left) {
                    st.push(front->left);
                }
                if (front->right) {
                    st.push(front->right);
                }
            }
            res.push_back(currLevel);
            leftToRight =!leftToRight;
        }
        return res;
    }
};
