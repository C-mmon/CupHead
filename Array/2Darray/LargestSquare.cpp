#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// Check if there exists a subarray of length k where all elements >= k
bool canFit(const vector<int>& cityline, int k) {
    deque<int> dq;  // will store indices, min value at front
    int n = cityline.size();

    for (int i = 0; i < n; ++i) {
        // Remove elements from back that are >= current element (keep deque increasing)
        while (!dq.empty() && cityline[dq.back()] >= cityline[i]) {
            dq.pop_back();
        }
        dq.push_back(i);

        // Remove indices out of the current window [i-k+1, i]
        if (dq.front() <= i - k) {
            dq.pop_front();
        }

        // Once window size reached, check if minimum in window >= k
        if (i >= k - 1) {
            if (cityline[dq.front()] >= k) {
                return true;
            }
        }
    }
    return false;
}

int solution(const vector<int>& cityline) {
    int left = 1, right = cityline.size();
    int best = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (canFit(cityline, mid)) {
            best = mid;         // we can fit square of side mid
            left = mid + 1;     // try for bigger square
        } else {
            right = mid - 1;    // try smaller square
        }
    }
    return best * best;  // area of largest square
}

int main() {
    vector<int> cityline = {1, 2, 3, 2, 1};
    cout << solution(cityline) << endl; // Output: 4
    return 0;
}
