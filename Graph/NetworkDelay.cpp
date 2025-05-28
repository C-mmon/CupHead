class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // adjacency list banado mast, use classic pair method
        vector<pair<int,int>> adj[n+1]; 
        // <!-- min heap banadia ek jo min distance dega bar bar priority queue m  -->
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater <pair<int,int>>> pq;

        // <!-- directed hai to ek sided list define kardi  -->

        for( auto it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }

        // <!-- sabki distance ko k node se initially infinite mark krdia -->
        vector<int> dist(n+1, 1e9);

        // <!-- node k ki node k se distance to 0 hi hogi  -->
        dist[k] =0;
        pq.push({0,k});

        // <!-- iteration traversal BFS starts -->

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dis = it.first;
            int node = it.second;

            // <!-- ab har node ko pura check karna hai ek edge at a time -->

            for( auto it : adj[node]){
                int adjnode = it.first;
                int wt = it.second;

                // <!-- agar distance kam ayi kisi tarah to us node ki dist update kardo kam wali -->

                if(dist[adjnode] > dis +wt){
                    dist[adjnode] = wt+dis;
                    pq.push({dis+wt, adjnode});
                }
            }
        }

        // <!-- max distance node k se is the weight taken to spread in whole graph -->
        int ans = 0; 
        for ( int i=1;i<dist.size(); i++){
            ans = max(ans, dist[i]);
        }

        // <!-- agar visit hi nahi hua to -1 return karo  -->
        
        if( ans == 1e9) return -1;
        return ans;


        
    }
};
