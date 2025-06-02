#include <iostream>
#include <unordered_map>
#include <deque>
#include <string>

using namespace std;

class Logger {
private:
    const int WINDOW_SIZE = 10;
    deque<pair<int, string>> window;
    unordered_map<string, deque<pair<int,string>>::iterator> msgMap;

    void evictOldMessages(int currentTimestamp) {
        while (!window.empty() && window.front().first <= currentTimestamp - WINDOW_SIZE) {
            msgMap.erase(window.front().second);
            window.pop_front();
        }
    }

public:
    bool shouldPrint(int timestamp, const string& message) {
        evictOldMessages(timestamp);

        if (msgMap.find(message) != msgMap.end()) {
            // Message seen within 10 seconds; do not print
            return false;
        }

        // Insert new message at back and store iterator in map
        window.emplace_back(timestamp, message);
        auto it = prev(window.end());
        msgMap[message] = it;

        return true;
    }
};

int main() {
    vector<string> inputs = {
        "10 solar panel activated",
        "11 low battery warning",
        "12 tire one: low air pressure",
        "13 solar panel activated",
        "14 low battery warning",
        "21 solar panel activated",
        "35 solar panel activated"
    };

    Logger logger;

    for (const auto& input : inputs) {
        size_t pos = input.find_first_of(" \t\n\r");
        int timestamp = stoi(input.substr(0, pos));
        string message = input.substr(pos + 1);

        if (logger.shouldPrint(timestamp, message)) {
            cout << timestamp << " " << message << endl;
        }
    }
    return 0;
}
