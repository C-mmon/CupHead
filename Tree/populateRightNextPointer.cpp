/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
            if (!root) return nullptr;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int qSize = q.size();
        Node* rightNode = nullptr;

        for (int i = 0; i < qSize; i++) {
            Node* curr = q.front();
            q.pop();

            curr->next = rightNode;
            rightNode = curr;

            // Push right child first so that left is processed last and points to right
            if (curr->right) q.push(curr->right);
            if (curr->left) q.push(curr->left);
        }
    }

    return root;
    }
};
