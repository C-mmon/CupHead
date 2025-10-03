#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <ctime>
#include <uuid/uuid.h>

using namespace std;

// Utility function to generate UUIDs
string generateUUID() {
    uuid_t id;
    uuid_generate(id);
    char str[37];
    uuid_unparse(id, str);
    return string(str);
}

// TimeSlot Class
class TimeSlot {
public:
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;

    TimeSlot(int sh, int sm, int eh, int em) :
        startHour(sh), startMinute(sm), endHour(eh), endMinute(em) {}

    bool overlaps(const TimeSlot& other) {
        int start1 = startHour * 60 + startMinute;
        int end1 = endHour * 60 + endMinute;
        int start2 = other.startHour * 60 + other.startMinute;
        int end2 = other.endHour * 60 + other.endMinute;
        return (start1 < end2 && start2 < end1);
    }
};

// Forward declarations
class User;

enum BookingStatus { PENDING, CONFIRMED, CANCELLED };

// Booking Class
class Booking {
public:
    string id;
    string userId;
    string turfId;
    time_t date;  // Booking date
    TimeSlot slot;
    BookingStatus status;

    Booking(string uId, string tId, time_t d, TimeSlot s) :
        id(generateUUID()), userId(uId), turfId(tId), date(d), slot(s), status(PENDING) {}
};

// Turf Class
class Turf {
public:
    string id;
    string name;
    string location;
    string ownerId;
    map<time_t, vector<TimeSlot>> availability; // date -> list of slots

    Turf(string n, string loc, string oId) : 
        id(generateUUID()), name(n), location(loc), ownerId(oId) {}

    void updateAvailability(time_t date, vector<TimeSlot> slots) {
        availability[date] = slots;
    }

    bool isAvailable(time_t date, TimeSlot s) {
        if(availability.find(date) == availability.end()) return false;
        for(const auto& slot : availability[date]) {
            if(slot.overlaps(s)) return true;
        }
        return false;
    }
};

// Owner Class
class Owner {
public:
    string id;
    string name;
    vector<Turf*> turfs;

    Owner(string n) : id(generateUUID()), name(n) {}

    void addTurf(Turf* t) {
        turfs.push_back(t);
    }

    void removeTurf(string turfId) {
        turfs.erase(remove_if(turfs.begin(), turfs.end(),
                    [&](Turf* t){ return t->id == turfId; }), turfs.end());
    }

    void updateAvailability(string turfId, time_t date, vector<TimeSlot> slots) {
        for(auto* turf : turfs) {
            if(turf->id == turfId) {
                turf->updateAvailability(date, slots);
                break;
            }
        }
    }
};

// User Class
class User {
public:
    string id;
    string name;
    vector<Booking*> bookings;

    User(string n) : id(generateUUID()), name(n) {}

    Booking* bookTurf(Turf* turf, time_t date, TimeSlot slot) {
        if(!turf->isAvailable(date, slot)) {
            cout << "Turf not available for this slot!" << endl;
            return nullptr;
        }
        Booking* booking = new Booking(id, turf->id, date, slot);
        bookings.push_back(booking);
        cout << "Booking created with ID: " << booking->id << endl;
        return booking;
    }
};

int main() {
    // Example Usage
    Owner owner("John");
    Turf* turf1 = new Turf("Green Turf", "Mumbai", owner.id);
    owner.addTurf(turf1);

    // Set availability
    time_t today = time(nullptr);
    turf1->updateAvailability(today, {TimeSlot(10,0,11,0), TimeSlot(11,0,12,0)});

    User user("Alice");
    user.bookTurf(turf1, today, TimeSlot(10,0,11,0)); // Should succeed
    user.bookTurf(turf1, today, TimeSlot(10,30,11,30)); // Overlaps, but current simple check may allow partial overlaps

    return 0;
}
