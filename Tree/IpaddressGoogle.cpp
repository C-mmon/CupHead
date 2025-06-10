//Van Embda Boas Tree
IP_Address_Start,IP_Address_End,City,Region,Country
192.168.1.1,192.168.1.255,New York,NY,USA
10.0.0.1,10.0.0.255,London,ENG,GBR
172.16.0.1,172.16.0.100,Tokyo,Tokyo,JPN
203.0.113.0,203.0.113.50,Paris,IDF,FRA
203.0.113.51,203.0.113.100,Berlin,BER,DEU

    std::string ip = "192.168.0.1";
    std::stringstream ss(ip);
    std::string token;

    while (getline(ss, token, '.')) {
        std::cout << token << std::endl;
    }

    return 0;

    #include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct IPRange {
    uint32_t start;
    uint32_t end;
    string city;
};

// Converts dotted IP string (e.g., "1.0.0.1") to a 32-bit integer
uint32_t ipToInt(const string& ip) {
    stringstream ss(ip);
    string token;
    uint32_t result = 0;
    for (int i = 0; i < 4; ++i) {
        getline(ss, token, '.');
        result = (result << 8) + stoi(token);
    }
    return result;
}

// Performs binary search on sorted IP ranges
string findCity(const vector<IPRange>& ranges, uint32_t ip) {
    int left = 0, right = ranges.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        const IPRange& r = ranges[mid];

        if (r.start <= ip && ip <= r.end) {
            return r.city;
        } else if (ip < r.start) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return "Unknown";
}

int main() {
    // Hardcoded IP ranges
    vector<IPRange> ranges = {
        {ipToInt("1.0.0.0"), ipToInt("1.0.0.255"), "Sydney"},
        {ipToInt("1.0.1.0"), ipToInt("1.0.3.255"), "Melbourne"},
        {ipToInt("1.0.4.0"), ipToInt("1.0.7.255"), "Brisbane"}
    };

    // Sort ranges by start IP for binary search
    sort(ranges.begin(), ranges.end(), [](const IPRange& a, const IPRange& b) {
        return a.start < b.start;
    });

    // Query IPs
    vector<string> queries = {
        "1.0.0.1",
        "1.0.2.5",
        "1.0.6.10",
        "8.8.8.8" // Unknown
    };

    // Process each query
    for (const string& ip : queries) {
        uint32_t ipInt = ipToInt(ip);
        string city = findCity(ranges, ipInt);
        cout << ip << " => " << city << endl;
    }

    return 0;
}
