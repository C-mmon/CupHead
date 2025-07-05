#include <iostream>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

class Solution {
public:
TreeNode* ans =NULL;
TreeNode* potentialAnswer;
    void findDeepestRightmost(TreeNode* node) {
        if(ans || !node || (node->left== NULL && node->right == NULL))
        {
            return ;
        }
        if(node->left && !node->right)
        {
            ans = node->left;
        }
        else if(node->left && node->right)
        {
            potentialAnswer = node->right;
         findDeepestRightmostNode(node->left);
         findDeepestRightmostNode(node->right);
        }
        return ;
    }

    TreeNode* findDeepestRightmostNode(TreeNode* root) {
        if (!root) return nullptr;
        findDeepestRightmost(root);
        if(ans == NULL)
        {
            return potentialAnswer;
        }
        else 
        {
            return ans;
        }
    }
};

// Optional: helper to build and test
int main() {
    /*
        Tree Structure:
               1
             /   \
            2     3
           / \   / \
          4   5 6   7
          
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution sol;
    TreeNode* ans = sol.findDeepestRightmostNode(root);
    if (ans) {
        cout << "Deepest rightmost node value: " << ans->val << endl;
    } else {
        cout << "Tree is empty" << endl;
    }

    return 0;
}
