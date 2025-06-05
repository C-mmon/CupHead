#include <bits/stdc++.h>
using namespace std;

// Returns {maximum product, the subarray achieving it}
pair<long long, vector<int>> maxProductSubarray(const vector<int>& nums) {
    if (nums.empty()) 
        return {0, {}};

    long long max_prod = nums[0];
    long long min_prod = nums[0];
    long long ans = nums[0];
    int start_max = 0, start_min = 0;
    int ans_start = 0, ans_end = 0;

    for (int i = 1; i < (int)nums.size(); ++i) {
        long long n = nums[i];

        // If negative, swap max and min trackers
        if (n < 0) {
            swap(max_prod, min_prod);
            swap(start_max, start_min);
        }

        // Decide whether to start a new subarray or extend
        if (n > max_prod * n) {
            max_prod = n;
            start_max = i;
        } else {
            max_prod *= n;
        }

        if (n < min_prod * n) {
            min_prod = n;
            start_min = i;
        } else {
            min_prod *= n;
        }

        // Update global answer
        if (max_prod > ans) {
            ans = max_prod;
            ans_start = start_max;
            ans_end = i;
        }
    }

    vector<int> best_subarray(
        nums.begin() + ans_start,
        nums.begin() + ans_end + 1
    );
    return {ans, best_subarray};
}

int main() {
    vector<vector<int>> tests = {
        {2, 3, -2, 4},
        {-2, 0, -1},
        {-2, 3, -4},
        {0, 2},
        {-2},
        {-1, -3, -10, 0, 60},
        {-2, -3, 0, -2, -40},
    };

    for (auto& arr : tests) {
        auto [prod, sub] = maxProductSubarray(arr);
        cout << "nums = [";
        for (int i = 0; i < (int)arr.size(); ++i) {
            cout << arr[i] << (i + 1 < (int)arr.size() ? ", " : "");
        }
        cout << "] -> max product = " << prod << ", subarray = [";
        for (int i = 0; i < (int)sub.size(); ++i) {
            cout << sub[i] << (i + 1 < (int)sub.size() ? ", " : "");
        }
        cout << "]\n";
    }

    return 0;
}
