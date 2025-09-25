#include <bits/stdc++.h>
#include <thread>
#include <mutex>
using namespace std;

// Global store and its mutex
unordered_map<int,int> mp;
mutex mtx_;

// Per-thread transaction state
thread_local bool inTx = false;
thread_local unordered_map<int, optional<int>> write_set; // nullopt => delete

bool set_kv(int key, int value) {
    if (inTx) {
        write_set[key] = optional<int>(value);
        return true;
    } else {
        lock_guard<mutex> lg(mtx_);
        mp[key] = value;
        return true;
    }
}

bool delete_kv(int key) {
    if (inTx) {
        write_set[key] = nullopt;
        return true;
    } else {
        lock_guard<mutex> lg(mtx_);
        return mp.erase(key) > 0;
    }
}

// returns -1 if not found
int get_kv(int key) {
    if (inTx) {
        auto it = write_set.find(key);
        if (it != write_set.end()) {
            if (!it->second.has_value()) return -1; // deleted in tx
            return it->second.value();
        }
    }
    lock_guard<mutex> lg(mtx_);
    auto it = mp.find(key);
    return (it != mp.end()) ? it->second : -1;
}

void transactionBegin() {
    inTx = true;
    write_set.clear();
}

void commit() {
    if (!inTx) return;
    lock_guard<mutex> lg(mtx_);
    for (auto &p : write_set) {
        if (p.second.has_value()) mp[p.first] = p.second.value();
        else mp.erase(p.first);
    }
    write_set.clear();
    inTx = false;
}

void rollback() {
    if (!inTx) return;
    write_set.clear();
    inTx = false;
}

// Demo worker
void worker(int id) {
    transactionBegin();
    int v = get_kv(id);
    if (v == -1) v = 0;
    set_kv(id, v + 10);
    // optional delete example:
    if (id % 2 == 0) delete_kv((id + 1) % 5);
    commit();
}

int main() {
    // seed global store
    {
        lock_guard<mutex> lg(mtx_);
        for (int i = 0; i < 5; ++i) mp[i] = i;
    }

    vector<thread> threads;
    for (int t = 0; t < 8; ++t) threads.emplace_back(worker, t % 5);
    for (auto &th : threads) th.join();

    // print final store
    {
        lock_guard<mutex> lg(mtx_);
        for (auto &p : mp) cout << "key=" << p.first << " val=" << p.second << '\n';
    }
    return 0;
}
