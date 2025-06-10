#include <bits/stdc++.h>
using namespace std;

// Convert "HH:MM" to minutes
int parseTime(const string& timeStr) {
    int hours = stoi(timeStr.substr(0, 2));
    int minutes = stoi(timeStr.substr(3, 2));
    return hours * 60 + minutes;
}

struct Train {
    int id;
    string from;
    string to;
    int departTime;
    int arriveTime;

    Train(int id_, const string& from_, const string& to_,
          const string& departStr, const string& arriveStr)
        : id(id_), from(from_), to(to_),
          departTime(parseTime(departStr)),
          arriveTime(parseTime(arriveStr)) {}
};

class TrainNetwork {
private:
    unordered_map<string, vector<Train>> graph;

public:
    void addTrain(const Train& train) {
        graph[train.from].push_back(train);
    }

    bool dfs(const string& currCity, const string& endCity,
             int arrivalTime, int deadline,
             unordered_set<string>& visited) {
        if (currCity == endCity) return true;
        if (visited.count(currCity)) return false;

        visited.insert(currCity);

        for (const auto& adjTrain : graph[currCity]) {
            if (arrivalTime <= adjTrain.departTime &&
                adjTrain.arriveTime <= deadline) {
                if (dfs(adjTrain.to, endCity, adjTrain.arriveTime, deadline, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool canReach(const string& startCity, const string& endCity,
                  const string& startTimeStr, const string& deadlineStr, int n) {
        if (graph.find(startCity) == graph.end() || graph.find(endCity) == graph.end()) {
            return false;
        }

        int startTime = parseTime(startTimeStr);
        int deadline = parseTime(deadlineStr);

        unordered_set<string> visited;
        return dfs(startCity, endCity, startTime, deadline, visited);
    }
};

int main() {
    TrainNetwork network;
    network.addTrain(Train(1, "c1", "c3", "12:00", "13:10"));
    network.addTrain(Train(2, "c3", "c5", "14:00", "15:00"));

    string startCity = "c1";
    string endCity = "c5";
    string startTime = "10:00";
    string deadline = "16:00";

    int n = 5;  // total trains
    bool result = network.canReach(startCity, endCity, startTime, deadline, n);
    cout << (result ? "True" : "False") << endl;

    return 0;
}
