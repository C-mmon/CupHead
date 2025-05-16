#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<string, int>> getTopTalkersWithTies(const vector<string>& logs, int K) {
    unordered_map<string, int> wordCount;

    for (const string& line : logs) {
        size_t start = line.find('<');
        size_t end = line.find('>');

        if (start == string::npos || end == string::npos || end <= start + 1) continue;

        string user = line.substr(start + 1, end - start - 1);
        string message = line.substr(end + 1);

        // Count words in the message
        istringstream ss(message);
        string word;
        while (ss >> word) {
            wordCount[user]++;
        }
    }

    // Min heap: {wordCount, username}
    auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
        if (a.first == b.first)
            return a.second > b.second; // tie-breaker: lexicographically smaller first
        return a.first > b.first;
    };

    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

    for (const auto& entry : wordCount) {
        pq.push({entry.second, entry.first});
        if (pq.size() > K) {
            pq.pop();
        }
    }

    // Find cutoff frequency
    vector<pair<string, int>> result;
    int cutoff = pq.top().first;

    // Add everything with frequency >= cutoff
    for (const auto& entry : wordCount) {
        if (entry.second > cutoff) {
            result.emplace_back(entry.first, entry.second);
        }
    }
    for (const auto& entry : wordCount) {
        if (entry.second == cutoff) {
            result.emplace_back(entry.first, entry.second);
        }
    }

    // Sort final result for deterministic output
    sort(result.begin(), result.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    });

    return result;
}
