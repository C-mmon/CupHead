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
int res =0;
unordered_map <int, vector <int>> graph;
unordered_set <int> visited;
    int amountOfTime(TreeNode* root, int start) {
        // build the adjacency graph
        buildGraph(root);

        //perform dfs to find the maximum time
        dfs(start, 0);

        return res;
    }
    void buildGraph(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        if(root->left)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left);
        }
        if(root->right)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right);
        }
    }
    void dfs(int node, int w)
    {
        visited.insert(node);
        res = max(res, w); // update maximum time
        for(auto child: graph[node])
        {
            if(visited.find(child) == visited.end())
            {
                dfs(child, w+1);
            }
        }
    }
};

//If multiple nodes are affected, then we need to push all the nodes and then perform a bfs, so 
Put all infected nodes in the queue initially with time = 0.

Maintain a visited set (or map) so you do not revisit nodes.

Pop from queue, push unvisited neighbors with time + 1.

Keep updating res = max(res, time).
