#include <vector>
#include <unordered_map>
#include <map>   // Include if you want to use map instead of unordered_map
#include <algorithm> // For max
#include <climits>   // For INT_MIN

using namespace std;

// Helper function to check if it's possible to fill `mid` baskets
bool checkArrangementPossible(int mid, const map<int, int>& mp, int k) {
    long long total = 0;
    for (auto [color, cnt] : mp) {
        total += min(cnt, mid);
    }
    return total >= (long long)k * mid;
}

int main()
{
    // Example input: balls of these colors
    vector<int> color = {1, 2, 2, 3, 3, 3}; // replace with your data
    int k = 2; // Minimum distinct colors per basket (set as per the problem)
    int N = color.size();

    // Build color frequency map
    map<int, int> mp;
    for (int i = 0; i < N; i++) {
        mp[color[i]]++;
    }

    // Binary search for the maximum number of baskets
    int left = 0;
    int right = N / k; // Max possible baskets
    int answer = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (checkArrangementPossible(mid, mp, k)) {
            answer = mid;   // Possible, try for more
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    // `answer` is the maximum count of baskets
    cout << "Maximum Baskets: " << answer << endl;
    return 0;
}
