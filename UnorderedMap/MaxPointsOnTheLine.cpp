#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

class Solution {
public:

// Standard GCD function
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Custom hash function for pair<int, int>
struct pair_hash {
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // safer hashing
    }
};

int maxPoints(vector<vector<int>>& points) {
    int res = 0;
    int n = points.size();
    if (n <= 2) return n;

    for (int i = 0; i < n; i++) {
        unordered_map<pair<int, int>, int, pair_hash> umap;
        int duplicates = 0;
        int localMax = 0;
        int x1 = points[i][0];
        int y1 = points[i][1];

        for (int j = i + 1; j < n; j++) {
            int x2 = points[j][0];
            int y2 = points[j][1];
            int diffY = y2 - y1;
            int diffX = x2 - x1;

            if (diffY == 0 && diffX == 0) {
                duplicates++;
                continue;
            }

            int gcdValue = gcd(abs(diffY), abs(diffX)); // Take absolute value to avoid negative gcd
            diffY /= gcdValue;
            diffX /= gcdValue;

            // Normalize slope: ensure diffX > 0, or diffX == 0 and diffY > 0
            if (diffX < 0) {
                diffX = -diffX;
                diffY = -diffY;
            }
            if (diffX == 0 && diffY < 0) {
                diffY = -diffY;
            }
            //we do not need the intercept because we are making the base point fixed.

            umap[{diffX, diffY}]++;
            localMax = max(localMax, umap[{diffX, diffY}]);
        }

        res = max(res, localMax + duplicates + 1); // +1 for the starting point itself
    }
    return res;
}

};
