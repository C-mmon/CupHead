#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>

using namespace std;

// Dummy parser for testing; implement your own for real timestamps
pair<string, int> parseTimestamp(const string& timestamp) {
    // Example: "Tuesday 01:30AM" => ("Tuesday", 90)
    return {"Tuesday", 90};  // 1:30 AM
}

bool isOpen(const unordered_map<string, vector<pair<int, int>>>& schedule, const string& timestamp) {
    pair<string, int> timeInfo = parseTimestamp(timestamp);
    string day = timeInfo.first;
    int minutes = timeInfo.second;

    vector<string> week = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    unordered_map<string, int> dayIndex;
    for (int i = 0; i < 7; ++i) dayIndex[week[i]] = i;

    int today = dayIndex[day];
    int prev = (today - 1 + 7) % 7;
    string prevDay = week[prev];
    
    // Step 1: Check previous day for wrap-around intervals (start > end)
    if (schedule.count(prevDay)) {
        for (const auto& interval : schedule.at(prevDay)) {
            int start = interval.first;
            int end = interval.second;
            if (start > end && minutes < end) {
                return true;
            }
        }
    }

    // Step 2: Check current day's intervals
    if (schedule.count(day)) {
        for (const auto& interval : schedule.at(day)) {
            int start = interval.first;
            int end = interval.second;
            if (start > end) {  // wrap-around, only valid from start to 1439 on current day
                if (minutes >= start) return true;
            } else {  // normal case
                if (minutes >= start && minutes < end) return true;
            }
        }
    }

    return false;
}

int main() {
    unordered_map<string, vector<pair<int, int>>> schedule;

    schedule["Monday"].push_back({1380, 120});   // 11:00 PM to 2:00 AM next day
    schedule["Tuesday"].push_back({0, 240});     // 12:00 AM to 4:00 AM
    schedule["Tuesday"].push_back({600, 900});   // 10:00 AM to 3:00 PM

    string timestamp = "Tuesday 01:30AM"; // Should return true

    bool open = isOpen(schedule, timestamp);
    cout << "Is the restaurant open? " << (open ? "Yes" : "No") << endl;

    return 0;
}
