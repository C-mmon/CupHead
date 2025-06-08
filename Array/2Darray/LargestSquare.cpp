At first glance, I thought it looked like a variant of largest rectangle in histogram.
But then I realized there is a unique way to solve this.
You could first simply start with binary search. we know the max size of the square can be in the range max value of that element and min value.
But we can add another twist to it, while we are performing a binary search, we can then maintain a deque.
For example, we can use a deque to track the min element encountered so far.

Now, the question gets broken down, does there exist, a sub-array with length k, where all the element size is greater than k.

The problem with sliding window is that, we can end up iterating O(n*k).
This is where we try to optimize it, now note, when we are traversing, if we had used a deque, we would simply remove first out of bound index, and then remove the entry which are not less than k.

Too maintain a monotonic increasing dequeue, what you need is, in case if you have found smaller element than the back element of the dequeu, you pop it.
after that you can push the currrent element, now further, from the front, you need to remove out of bound indices.
The reason you want to have dequeue because you want to access the min element of the window in O(1)
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
// what is the reason for adding 0, now imagine that, if we pop a skyscrapper at index 0, the shortest one we have so far.
// The stack is now empty and whhen we try stk.back(), it will crash, hence we add -1 to act as a floor.
//we push 0 at the back, lets take an example, where the stack was entirely increasing and we encounter no, shorter skyscrapper.,
// with 0, we will encounter the case, where it will start the calculation.

int solve(vector<int>& heights) {
    const int n = (int)heights.size();
    heights.push_back(0);
    vector stk {-1};
    int mx = 0;
    for (int i = 0; i <= n; i++) {
        while (stk.size() > 1 && heights[stk.back()] >= heights[i]) {
            const int h = heights[stk.back()];
            stk.pop_back();
            const int w = i - stk.back() - 1;
            mx = max(mx, min(h, w));
        }
        stk.push_back(i);
    }
    return mx * mx;
}
