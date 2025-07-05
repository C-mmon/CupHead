class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
        if (source == target) {
            return 0;
        }

        unordered_map<int, unordered_set<int>> busesAgainstStation;
        int i = 0;
        for (auto route : routes) {
            for (int station : route) {
                busesAgainstStation[station].insert(i);
            }
            i++;
        }

        queue<pair<int, int>> q;
        unordered_set<int> visitedStation;
        visitedStation.insert(source);
        for (auto busId : busesAgainstStation[source]) {
            q.push({busId, 1}); // we took the bus ia
        }

        vector<int> visited(routes.size(), -1);
        while (!q.empty()) {
            int busId = q.front().first;
            int step = q.front().second;
            q.pop();
            for (int station : routes[busId]) {
                if (station == target) {
                    return step;
                }
                if (visitedStation.find(station) == visitedStation.end()) {
                    for (int nextBus : busesAgainstStation[station]) {
                        if (visited[nextBus] == -1) {
                            //mark this bus early
                            visited[nextBus] = 1;
                            q.push({nextBus, step + 1});
                        }
                    }
                    //mark this station as visited
                    visitedStation.insert(station);
                }
            }
        }
        return -1;
    }
};
