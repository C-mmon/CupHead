
class BSTIterator {
public:
    stack<TreeNode*> store;
    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != NULL) {
            store.push(curr);
            curr = curr->left;
        }
    }

    int next() {
        TreeNode* topElement;
        if (!store.empty()) {
            topElement = store.top();
            store.pop();
            TreeNode* rightSide = topElement->right;
            while (rightSide != NULL) {
                store.push(rightSide);
                rightSide = rightSide->left;
            }
        }
        return topElement->val;
    }

    bool hasNext() {
        if (!store.empty()) {
            return true;
        }
        return false;
    }
};
