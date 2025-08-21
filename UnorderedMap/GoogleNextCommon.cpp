#include <bits/stdc++.h>
using namespace std;

class NextWordAPI {
    unordered_map<string, unordered_map<string, int>> follow_map;

public:
    NextWordAPI(const vector<vector<string>>& sentences) {
        for (const auto& sentence : sentences) {
            for (size_t i = 0; i + 1 < sentence.size(); i++) {
                follow_map[sentence[i]][sentence[i + 1]]++;
            }
        }
    }

    string mostFrequentNext(const string& word) {
        if (follow_map.find(word) == follow_map.end()) return "";
        auto& nextWords = follow_map[word];
        return max_element(nextWords.begin(), nextWords.end(),
                           [](auto& a, auto& b) { return a.second < b.second; })
            ->first;
    }
};

int main() {
    vector<vector<string>> sentences = {
        {"hi", "my", "name", "is", "X"},
        {"how", "is", "my", "cat", "doing"},
        {"did", "my", "cat", "eat"},
        {"what", "did", "my", "cat", "eat"}
    };

    NextWordAPI api(sentences);
    cout << api.mostFrequentNext("my") << endl; // Outp
