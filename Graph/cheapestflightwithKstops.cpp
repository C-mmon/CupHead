class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //create a graph, but note we are using pair, becauser we are storing the flight cost as well.
        vector <pair <int, int>> graph[n];
        for(auto& flight: flights)
        {
            graph[flight[0]].push_back({flight[1], flight[2]});
            //push the element distance and flightCost to the source
        }

        //we are using a distance array now remember, 
        vector <int> distance (n,1e9);

        //instead of piority queue, we are using queue, because stops are increasing in order
        //we will discuss
        queue <  pair <int ,pair<int,int>> > q;

        //to reach the situation where destination and source are same, we need zero stop 
        q.push({0, {src, 0}});

        while(!q.empty())
        {
            //pop the element from the queue
            auto elementFromQ = q.front();
            int cost = elementFromQ.second.second;
            int node = elementFromQ.second.first;
            int stops = elementFromQ.first;

            q.pop(); 
            //now base case: 
            if(stops> k)
            {
                continue;
            }

            //core peice: iterator over all the adjacent element 
            for(auto iter: graph[node])
            {
                int adjNode = iter.first;
                int adjNodeCost = iter.second;
                //some loop
                if(cost+ adjNodeCost < distance[adjNode])
                {
                    //update the distance vector 
                    distance[adjNode] = cost + adjNodeCost;
                    q.push({stops+1,{adjNode, cost+adjNodeCost}});
                }
            }
        }
        if(distance[dst]  == 1e9)
        {
            return -1;
        }
        return distance[dst];
    }
};