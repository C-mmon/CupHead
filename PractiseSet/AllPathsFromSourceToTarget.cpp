class Solution {
public:
void dfs(int currNode, vector <int> &path, vector <vector <int>> &gpath, vector<vector<int>>& graph)
{
    path.push_back(currNode);
    if(currNode == graph.size()-1)
    {
        gpath.push_back(path);
    }
    else
    {
        for(auto it: graph[currNode])
        {
            dfs(it, path,gpath, graph);
        }
    }
    path.pop_back();
}

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector <vector <int>> gpath;
        vector <int> path;
        dfs(0, path, gpath, graph);
        return gpath;
    }
};
