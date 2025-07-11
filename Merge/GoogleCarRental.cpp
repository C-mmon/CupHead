#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> events = {
        {1, 3}, {2, 5}, {6, 8}, {7, 10}, {9, 10}
    };

    // Sort by start time
    sort(events.begin(), events.end());

    // minHeap stores {endTime, groupIndex}
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > minHeap;

    unordered_map<int, vector<pair<int, int>>> mp;
    int groupCount = 0;

    for (auto &event : events) {
        int start = event.first;
        int end = event.second;

        if (!minHeap.empty() && minHeap.top().first < start) {
            // Reuse the group
            int groupIndex = minHeap.top().second;
            minHeap.pop();
            mp[groupIndex].push_back({start, end});
            minHeap.push({end, groupIndex});
        } else {
            // Create a new group
            mp[groupCount].push_back({start, end});
            minHeap.push({end, groupCount});
            groupCount++;
        }
    }

    // Print the grouped intervals
    for (auto &[groupIndex, intervals] : mp) {
        cout << "Group " << groupIndex << ":\n";
        for (auto &[s, e] : intervals) {
            cout << "[" << s << ", " << e << "]\n";
        }
    }

    return 0;
}
