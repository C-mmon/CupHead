class HitCounter {
public:
    HitCounter() : totalHits(0) {}

    // Record a hit at timestamp t (t can be out of order)
    void hit(int t) {
        counts[t]++;
        totalHits++;
    }

    // Return the number of hits in the past 300 seconds up to timestamp t
    int getHits(int t) {
        int expire = t - WINDOW;
        // Evict all timestamps older than expire
        auto it = counts.begin();
        while (it != counts.end() && it->first <= expire) {
            totalHits -= it->second;
            it = counts.erase(it);
        }
        return totalHits;
    }

private:
    static constexpr int WINDOW = 300;
    map<int,int> counts;
    int totalHits;
};

class HitCounter {
public:
    static constexpr int WINDOW = 300;

    HitCounter() {
        times.assign(WINDOW, 0);
        hits.assign(WINDOW, 0);
    }

    // Record a hit at timestamp t (in seconds).  Timestamps may arrive out of order.
    void hit(int t) {
        int idx = t % WINDOW;
        if (times[idx] != t) {
            // the bucket is stale: reset it for this timestamp
            times[idx] = t;
            hits[idx]  = 1;
        } else {
            // same second, just accumulate
            hits[idx]++;
        }
    }

    // Return the number of hits in the past WINDOW seconds up to timestamp t.
    int getHits(int t) {
        int total = 0;
        for (int i = 0; i < WINDOW; i++) {
            // only include hits within [t-WINDOW+1, t]
            if (t - times[i] < WINDOW) {
                total += hits[i];
            }
        }
        return total;
    }

private:
    vector<int> times;
    vector<int> hits;
};
