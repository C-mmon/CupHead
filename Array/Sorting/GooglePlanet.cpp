#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Merge function
vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& centersAndRadii) {
    vector<pair<int, int>> intervals;

    // Convert (c, r) to [c - r, c + r]
    for (auto& [c, r] : centersAndRadii) {
        intervals.emplace_back(c - r, c + r);
    }

    // Sort intervals based on start time
    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> merged;
    for (auto& interval : intervals) {
        if (merged.empty() || merged.back().second < interval.first) {
            // No overlap
            merged.push_back(interval);
        } else {
            // Overlap: merge intervals
            merged.back().second = max(merged.back().second, interval.second);
        }
    }

    return merged;
}

int main() {
    vector<pair<int, int>> centersAndRadii = {
        {5, 2}, {8, 1}, {9, 2}
    };

    vector<pair<int, int>> merged = mergeIntervals(centersAndRadii);

    cout << "Merged intervals: ";
    for (auto& [start, end] : merged) {
        cout << "[" << start << ", " << end << "] ";
    }
    cout << endl;

    return 0;
}
