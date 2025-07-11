class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> itinerary;

    void dfs(string curr) {
        auto& dests = graph[curr];
        while (!dests.empty()) {
            string next = *dests.begin();
            dests.erase(dests.begin());
            dfs(next);
        }
        itinerary.push_back(curr); // postorder
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }
        dfs("JFK");
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};
