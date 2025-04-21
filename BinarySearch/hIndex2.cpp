#include <vector>
#include <algorithm> // Required for sort

class Solution {
public:
    int hIndex(std::vector<int>& citations) {

        int n = citations.size();
        // Handle the edge case of an empty input
        if (n == 0) {
            return 0;
        }

        int lo = 0;
        int hi = n - 1;
        int first_qualifying_index = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Condition: Check if the number of papers from 'mid' onwards (n - mid)
            // is less than or equal to the citation count at 'mid' (citations[mid]).
            // If citations[mid] >= n - mid, it means citations[mid] is high enough
            // to support n - mid papers. 'mid' is a potential candidate for the
            // smallest index satisfying the condition. We store this index and
            // try to find an even smaller index by searching in the left half.
            if (citations[mid] >= n - mid) {
                first_qualifying_index = mid;
                hi = mid - 1; // Search in the left half
            } else {
                // If citations[mid] < n - mid, it means citations[mid] is too low.
                // We need a higher citation count, which will be at a larger index.
                lo = mid + 1; // Search in the right half
            }
        }

        // The h-index is the number of papers from the 'first_qualifying_index' onwards.
        return n - first_qualifying_index;
    }
};
