
//unordered_set<long long>  to store seen values
// Maintain curr_mex starting at x

// On add(y): insert into set and increment curr_mex while it's in the set

// On get(): return curr_mex directly

// Time Complexity
//add(y) → amortized O(1) + possible increments (which are at most once per number)

// get() → O(1). This is optimal if get() is frequent.


class MexTracker {
    unordered_set<long long> seen;
    long long curr_mex;
public:
    MexTracker(long long start) : curr_mex(start) {}

    void add(long long y) {
        seen.insert(y);
        while (seen.count(curr_mex)) {
            curr_mex++;
        }
    }

    long long get_mex() const {
        return curr_mex;
    }
