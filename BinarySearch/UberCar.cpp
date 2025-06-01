Interesting Problem
 For a given time T, each car i can reach any point in the interval [location[i] - speed[i] * T, location[i] + speed[i] * T].
 For all cars to meet, the intersection of all these intervals must be non-empty.
The slowest car is the one that would take the longest to cover that distance.
So if you set T = D/minSpd, you know for sure even the slowest car could go from one extreme to the other in time T. 
 the max time for that would be  hi = (maxPos - minPos) / minSpd;,

That means, in the worst case, all cars can meet somewhere in [minPos, maxPos] by time T, so canMeet(pos,spd,hi) will return true.

Now, finding minPos and maxPos which all car can reach is bascially, taking all the left bound and right bound of all the cars, and storing the max of the left bound and minof the right bound.
You dont want your cars to travel far away from the search range, and that can happen, when you only select the max of the left bound.
further, you dont want your cars to move out of boundary, and hence you would always select the minimum of right.

at any point, if left bound greater than right bound, its not possible, return false, which means, you need to decrease the time, that is you need to shift the low value to mid and try again.

Also this is also not a straight forward, integer problem you need to run iteration of low and high, something similar to leetcode question separate square, because it might be possible, that the answer might end up rounding up to certain decimal range.

Personally, if this question was asked on leetcode, it would have been rated medium.
But since its asked during interview, I would say its a tough problem.


#include <bits/stdc++.h>
using namespace std;

// Return true if all cars can meet within time T.
bool canMeet(const vector<double>& pos,
             const vector<double>& spd,
             double T) {
    double left = -1e18, right = 1e18;
    for (int i = 0; i < (int)pos.size(); i++) {
        left = max(left,  pos[i] - spd[i] * T);
        right = min(right, pos[i] + spd[i] * T);
        if (left > right) return false;
    }
    return left <= right;
}

// Compute minimum time so that all cars can meet.
double minMeetingTime(vector<double>& pos, vector<double>& spd) {
    int n = pos.size();
    // Establish upper bound: max distance between extremes / min speed
    double lo = 0, hi = 0;
    double minSpd = *min_element(spd.begin(), spd.end());
    double minPos = *min_element(pos.begin(), pos.end());
    double maxPos = *max_element(pos.begin(), pos.end());
    hi = (maxPos - minPos) / minSpd;
    
    // Binary search for ~1e-6 precision
    for (int iter = 0; iter < 100; iter++) {
        double mid = (lo + hi) / 2.0;
        if (canMeet(pos, spd, mid)) hi = mid;
        else lo = mid;
    }
    return hi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<double> pos(n), spd(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> spd[i];
    }
    double ans = minMeetingTime(pos, spd);
    // Print with 6 digits after decimal (adjust as needed)
    cout << fixed << setprecision(6) << ans << "\n";
    return 0;
}
