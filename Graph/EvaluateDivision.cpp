class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adjList;

    double dfs(const string& curr, const string& target, unordered_set<string>& visited) {
        if (adjList.find(curr) == adjList.end() || adjList.find(target) == adjList.end())
            return -1.0;
        if (curr == target)
            return 1.0;

        visited.insert(curr);
        for (const auto& [neighbor, weight] : adjList[curr]) {
            if (!visited.count(neighbor)) {
                double res = dfs(neighbor, target, visited);
                if (res != -1.0)
                    return res * weight;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            const string& a = equations[i][0];
            const string& b = equations[i][1];
            double val = values[i];
            adjList[a].emplace_back(b, val);
            adjList[b].emplace_back(a, 1.0 / val);
        }

        vector<double> results;
        for (const auto& q : queries) {
            unordered_set<string> visited;
            double res = dfs(q[0], q[1], visited);
            results.push_back(res);
        }

        return results;
    }
};

//Each equation becomes two edge:
// a -> b : with weight val
// b -> a : with weight 1/val

//Core thing handle the case of negative logic over here

