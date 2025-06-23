#include <bits/stdc++.h>
using namespace std;

class MKAverage {
    int m, k;
    queue<int> q;
    multiset<int> low, mid, high;
    long long midSum = 0;

public:
    MKAverage(int m, int k) : m(m), k(k) {}

    void addElement(int num) {
        q.push(num);

        if ((int)q.size() <= m) {
            mid.insert(num);
            midSum += num;

            if ((int)q.size() == m) {
                initializePartitions();
            }
            return;
        }

        insert(num);

        int old = q.front(); q.pop();
        erase(old);

        rebalance();
    }

    int calculateMKAverage() {
        if ((int)q.size() < m) return -1;
        return midSum / (m - 2 * k);
    }

private:
    // 🔹 Step 1: Initialize low/mid/high from mid after first m insertions
    void initializePartitions() {
        // Move k smallest to low
        for (int i = 0; i < k; ++i) {
            auto it = mid.begin();
            low.insert(*it);
            midSum -= *it;
            mid.erase(it);
        }

        // Move k largest to high
        for (int i = 0; i < k; ++i) {
            auto it = prev(mid.end());
            high.insert(*it);
            midSum -= *it;
            mid.erase(it);
        }
    }

    // 🔹 Step 2: Insert new element into the correct partition
    void insert(int num) {
        if (num <= *low.rbegin()) {
            low.insert(num);
        } else if (num >= *high.begin()) {
            high.insert(num);
        } else {
            mid.insert(num);
            midSum += num;
        }
    }

    // 🔹 Step 3: Remove old element from the correct partition
    void erase(int num) {
        if (low.find(num) != low.end()) {
            low.erase(low.find(num));
        } else if (high.find(num) != high.end()) {
            high.erase(high.find(num));
        } else {
            mid.erase(mid.find(num));
            midSum -= num;
        }
    }

    // 🔹 Step 4: Rebalance the partitions to ensure sizes stay valid
    void rebalance() {
        // low too big → move largest to mid
        if ((int)low.size() > k) {
            auto it = prev(low.end());
            mid.insert(*it);
            midSum += *it;
            low.erase(it);
        }

        // low too small → move smallest from mid
        if ((int)low.size() < k && !mid.empty()) {
            auto it = mid.begin();
            low.insert(*it);
            midSum -= *it;
            mid.erase(it);
        }

        // high too big → move smallest to mid
        if ((int)high.size() > k) {
            auto it = high.begin();
            mid.insert(*it);
            midSum += *it;
            high.erase(it);
        }

        // high too small → move largest from mid
        if ((int)high.size() < k && !mid.empty()) {
            auto it = prev(mid.end());
            high.insert(*it);
            midSum -= *it;
            mid.erase(it);
        }
    }
};
