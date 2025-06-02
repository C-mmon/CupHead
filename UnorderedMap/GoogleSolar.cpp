#include <iostream>
#include <unordered_map>
#include <deque>
#include <string>
#include <functional> // for std::hash

using namespace std;

class Logger {
private:
    const int WINDOW_SIZE = 10;

    deque<pair<int, string>> window;
    unordered_map<size_t, deque<pair<int, string>>::iterator> msgMap;
    hash<string> hasher;

    void evictOldMessages(int currentTimestamp) {
        while (!window.empty() && window.front().first <= currentTimestamp - WINDOW_SIZE) {
            size_t oldHash = hasher(window.front().second);
            msgMap.erase(oldHash);
            window.pop_front();
        }
    }

public:
    bool shouldPrint(int timestamp, const string& message) {
        evictOldMessages(timestamp);

        size_t h = hasher(message);
        auto it = msgMap.find(h);
        if (it != msgMap.end()) {
            // Possible duplicate - verify strings to avoid hash collision issues
            if (it->second->second == message) {
                // Duplicate within window - suppress print
                return false;
            }
        }

        window.emplace_back(timestamp, message);
        auto dequeIt = prev(window.end());
        msgMap[h] = dequeIt;
        return true;
    }
};
