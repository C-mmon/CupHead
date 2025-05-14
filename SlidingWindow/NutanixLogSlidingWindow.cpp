#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

pair<string, int> most_requested_resource(const vector<vector<string>>& logs) {
    constexpr int WINDOW = 300; // 5 minutes
    unordered_map<string, vector<int>> resourceToTimes;

    // Step 1: Group access times by resource
    for (const auto& log : logs) {
        int time = stoi(log[0]);
        const string& resource = log[2];
        resourceToTimes[resource].push_back(time);
    }

    // Step 2: For each resource, apply sliding window
    string result_resource;
    int max_count = 0;

    for (auto& [resource, times] : resourceToTimes) {
        sort(times.begin(), times.end()); // Ensure times are sorted

        int left = 0;
        for (int right = 0; right < times.size(); ++right) {
            // Slide the window: keep only events within 300 seconds
            while (times[right] - times[left] > WINDOW) {
                left++;
            }
            int window_size = right - left + 1;
            if (window_size > max_count) {
                max_count = window_size;
                result_resource = resource;
            }
        }
    }

    return {result_resource, max_count};
}
