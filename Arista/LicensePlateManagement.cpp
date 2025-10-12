#include <iostream>
#include <map>
#include <vector>
#include <ctime>

struct License {
    int id;            // License identifier
    std::string name;  // License holder or type
    std::time_t expiry;// Expiry time as epoch
};

int main() {
    // Red-Black Tree: key is expiry time (epoch), value is License info
    std::map<std::time_t, License> licenseDB;

    // Insert licenses
    licenseDB[1672531200] = {1, "LicenseA", 1672531200}; // e.g., Jan 1 2023
    licenseDB[1704067200] = {2, "LicenseB", 1704067200}; // e.g., Jan 1 2024
    licenseDB[1735689600] = {3, "LicenseC", 1735689600}; // e.g., Jan 1 2025

    // Range query: find licenses expiring between Jan 1 2023 and Jan 1 2024
    std::time_t query_start = 1672531200; // Jan 1 2023
    std::time_t query_end   = 1704067200; // Jan 1 2024

    std::vector<License> result;

    // std::map is ordered—use lower_bound and upper_bound for fast range queries
    for (auto it = licenseDB.lower_bound(query_start); 
         it != licenseDB.upper_bound(query_end); ++it) {
        result.push_back(it->second);
    }

    // Print matched licenses
    for (const auto& lic : result) {
        std::cout << "License ID: " << lic.id 
                  << " Name: " << lic.name 
                  << " Expiry: " << lic.expiry << std::endl;
    }

    return 0;
}
