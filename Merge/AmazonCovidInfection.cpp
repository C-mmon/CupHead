#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

// Single event: time, user, room, enter/exit
struct Event {
    int time;
    std::string user;
    std::string room;
    bool enter;  // true=enter, false=exit

    bool operator<(Event const& o) const {
        if (time != o.time) return time < o.time;
        // exits before enters at same timestamp
        return enter == false && o.enter == true;
    }
};

// Parse "t, user, room, enter/exit"
Event parseLine(const std::string& line) {
    std::istringstream ss(line);
    Event e;
    std::string tok;
    std::getline(ss, tok, ','); e.time = std::stoi(tok);
    std::getline(ss, e.user,   ',');
    std::getline(ss, e.room,   ',');
    std::getline(ss, tok,      ','); 
    e.enter = (tok.find("enter") != std::string::npos);
    // trim whitespace
    auto trim = [&](std::string &s) {
        const char* ws = " \t\n\r\f\v";
        s.erase(0, s.find_first_not_of(ws));
        s.erase(s.find_last_not_of(ws) + 1);
    };
    trim(e.user);
    trim(e.room);
    return e;
}

// collect(): given all events and patient_zero, return all exposed users
std::set<std::string> collect(std::vector<Event>& events, 
                              const std::string& patient_zero) {
    // 1) sort events
    std::sort(events.begin(), events.end());

    // 2) state
    std::set<std::string> infected{ patient_zero };
    std::unordered_map<std::string, std::unordered_set<std::string>> occupants;
    std::unordered_map<std::string, int> infectedCount;

    // 3) sweep
    for (auto& ev : events) {
        auto& R = ev.room;
        auto& u = ev.user;

        if (ev.enter) {
            // Case A: u already infected → seed all current occupants
            if (infected.count(u)) {
                for (auto& v : occupants[R]) {
                    if (!infected.count(v)) {
                        infected.insert(v);
                        ++infectedCount[R];
                    }
                }
                ++infectedCount[R];
            }
            // Case B: room already has ≥1 infected → infect u
            else if (infectedCount[R] > 0) {
                infected.insert(u);
                ++infectedCount[R];
            }
            // Add to occupants
            occupants[R].insert(u);
        }
        else {
            // exit
            // remove from occupants
            occupants[R].erase(u);
            // if they were infected, decrement infectedCount
            if (infected.count(u)) {
                --infectedCount[R];
            }
        }
    }

    // drop the index case if you only want the others
    infected.erase(patient_zero);
    return infected;
}

int main() {
    std::vector<std::string> log = {
        "0,  Navi, meetingRoomA, enter",
        "5,  jeff, meetingRoomA, enter",
        "10, Navi, meetingRoomA, exit",
        "15, jeff, meetingRoomA, exit",
        "40, jeff, meetingRoomA, enter",
        "45, Carol, meetingRoomA, enter",
        "50, jeff, meetingRoomA, exit",
        "55, Carol, meetingRoomA, exit"
    };

    std::vector<Event> events;
    for (auto &line : log) {
        events.push_back(parseLine(line));
    }

    auto exposed = collect(events, "jeff");
    std::cout << "Exposed users:\n";
    for (auto &u : exposed) {
        std::cout << "  - " << u << "\n";
    }
    return 0;
}
