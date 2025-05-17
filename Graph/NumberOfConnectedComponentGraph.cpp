class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        //perform a bfs on the all the node or dfs maybe a better option
        if(n==0 || n==1)
        {
            return n;
        }
        unordered_map <int, vector <int>> adjList;
        for(auto i: edges)
        {
            adjList[i[0]].push_back(i[1]); //create a i[0] link to i[1]
            adjList[i[1]].push_back(i[0]); //create i[1] link to i[0]
        }
        vector <int> visited(n, false);
        int connectedCount=0;
        queue <int> q;
        for(int i=0; i< n;i++)
        {
            if(!visited[i])
            {
                q.push(i);
                while(!q.empty())
                {
                    int qSize = q.size();
                    while(qSize--)
                    {
                        
                    int front = q.front();
                    q.pop();
                    visited[front] = true;
                    for(auto k: adjList[front])
                    {
                        if(!visited[k])
                        {
                            q.push(k); //add to the queue if the given node is not visited
                        }
                    }
                    }
                }
                connectedCount++;
            }
            
            
        }
        return connectedCount;
    }
};
